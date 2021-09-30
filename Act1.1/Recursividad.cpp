/**
 * Jorge Del Barco Garza
 * A01284234
 * Agosto 12 de 2021
 * Descripción del programa: aprender las diferencias entre la recursión y la iteración
 * así como su nivel de complejidad.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Definición de funciones
long long sumaIterativa(long long n);
long long sumaRecursiva(long long n);
long long sumaDirecta(long long n);

int main(void)
{
    long long iterativa, recursiva, directa, archivo;

    string archivos[] = {"1.in", "2.in", "3.in", "4.in"};

    cout << "Escriba el # de archivo (1, 2, 3 o 4)\n";

    cin >> archivo;

    ifstream in(archivos[archivo-1]); // agarra un archivo diferente cada iteración.
    string s;
    getline(in, s);
    int k = stoi(s);
    long long *arreglo = new long long[k]; // Arreglo que almacena
    int i = 0;

    // Ciclo que lee el arreglo
    while (getline(in, s))
    {
        arreglo[i] = stoi(s);
        //cout << arreglo[i] << endl;
        i++;
    }

    for (int i = 0; i < k; i++)
    {
        cout << sumaRecursiva(arreglo[i]) <<  " " << sumaIterativa(arreglo[i]) << " " << sumaDirecta(arreglo[i]) << "\n";
    }
}
/*
    - Objetivo: Sumar de manera iterativa de 1 hasta 'n'.
    - {Param} int n - número hasta el cual se quiere sumar
    - Complejidad computacional: O(n) LINEAL

*/
long long sumaIterativa(long long n)
{
    long long suma = 0; // 1

    for (int i = 1; i <= n; i++) // n
    {
        suma = suma + i; // n - 1
    }
    return suma; // 1
}

/*
    - Objetivo: Sumar de manera recursiva todos los números del 1 hasta 'n'.
    - {Param} int n - número hasta el cual se quiere sumar.
    - Retorna: int suma - suma total de todos los números de 1 hasta 'n'.
    - Complejidad computacional: O(n) LINEAL

*/
long long sumaRecursiva(long long n)
{

    // Caso base
    if (n == 0 || n == 1) // 1
    {
        return 1; // 1
    }
    // Condición recursiva
    else
    {
        // La operación que queremos que haga la función se declara en el estatuto de retorno.
        return n + sumaRecursiva(n - 1); // n veces se repite.
    }
}

/*
   - Objetivo: Sumar de manera recursiva todos los números del 1 hasta 'n'.
    - {Param} int n - número hasta el cual se quiere sumar.
    - Complejidad computacional: O(1) constante

    Casos de prueba:

    I)
    input: n = 9
    output: 45

    II)
    input: n = 16
    output: 136

    III)
    input: n = 1
    output: 1

    IV)
    input: n = 10
    output: 55
*/
long long sumaDirecta(long long n)
{
    return (n * (n + 1)) / 2; // O(1)
}
