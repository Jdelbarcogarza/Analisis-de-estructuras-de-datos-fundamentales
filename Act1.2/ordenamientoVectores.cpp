#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>

using namespace std;

void swapElements(vector<int> &nums, int i, int j);
void printVector(vector<int> &nums);
void ordenaIntercambio(vector<int> &nums);
void ordenaBurbuja(vector<int> &nums);
void ordenaMerge(vector<int> &nums, int low, int high);
void merge(vector<int> &nums, int low, int mid, int high);
int busqSecuencial(vector<int> &nums, int n);
int busqBinaria(vector<int> &nums, int min, int max, int num);

int main(void)
{

    // Se declara vector
    vector<int> nums;

    int n;
    int newNum;
    string s;
    ifstream in("01.in"); // cambiar nombre de archivo que se desea utilizar E.j., 02.in, 03.in, 04.in

    in >> n; // cantidad de datos a leer.

    // loop de lectura
    for (int i = 0; i < n; i++)
    {
        in >> newNum;           // se lee el nuevo número del vector.
        nums.push_back(newNum); // se agrega el número al vector, como su fuera un append en Python.
    }

    int numOfSearches; // cantidad de busquedas a realizar

    cout << "Cuantas busquedas deseas realizar?\n";

    cin >> numOfSearches;

    int searchNum; // número que se desea buscar con los algoritmos de búsqueda.

    for (int i = 0; i < numOfSearches; i++)
    {

        cout << "Escribe el numero a buscar: ";
        cin >> searchNum;

        // Imprimir vector desordenado
        cout << "\nVector desordenado:\n";
        printVector(nums);

        cout << "Vector ordenado:\n";
        ordenaMerge(nums, 0, nums.size() - 1); // se sortea el vector
        printVector(nums);
        cout << "Resultado de busqueda (binary search): " << busqBinaria(nums, 0, nums.size() - 1, searchNum) << "\n";
        cout << "Resultado de busqueda (sequential search): " << busqSecuencial(nums, searchNum) << "\n\n";
    }

} // cierra main

void printVector(vector<int> &nums)
{
    // Loop de impresión
    for (auto i = nums.begin(); i != nums.end(); ++i)
    {
        /*
        Las funciones miembro de los vectores regresan iteradores (SON COMO APUNTADORES PERO NO LO SON)
        Por lo que lo que se deben de utilizar sintáxis parecidas para imprimir cosas.

        Reminder: 
        '&' para imprimir la ubicación en memoria.
        '*' para imprimir el valor en esa ubicación en memoria.
        */
        cout << *i << " ";
    }

    cout << "\n\n";
}

/*Función para cambiar de índice a dos elementos de una lista o array*/
void swapElements(vector<int> &nums, int i, int j)
{

    // Variable auxiliar para cambiar elementos de lugar
    int aux;

    aux = nums[i];     // variable temporal que guarda elementos.
    nums[i] = nums[j]; // Cambio de lugar de variable
    nums[j] = aux;     // la variable temporal cambia de lugar al valor que trae guardado.
}

/*
NOTES: 

When we pass an array to a function, a pointer is actually passed.

When a vector is passed to a function, a copy of the vector is created.
For example, we can see below program, changes made inside the function are not reflected
outside because function has a copy.

The above style of passing might also take a lot of time in cases of large vectors.
So it is a good idea to pass by reference.
*/

/*
Función de ordenamiento por intercambio.

Aqui en el parámetro del vector pasamos la referencia. Aka, dirección en memoria del vector.
*/
void ordenaIntercambio(vector<int> &nums)
{

    int i, j, aux;
    for (i = 0; i <= nums.size() - 2; i++)
    {
        /*se esta haciendo una comparación signed con unsigned int en 
         el condicional del for. ¿Cómo se repara? ¿Cómo hago para que la función
         .size() me regrese un signed int? */
        for (j = i + 1; j <= nums.size() - 1; j++)
        {
            if (nums[i] > nums[j])
            {
                swapElements(nums, i, j);
            }
        }
    }
}

void ordenaBurbuja(vector<int> &nums)
{
    int i, j;
    for (i = 0; i < nums.size() - 1; i++)
    {
        for (j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                /* Nos interesa hacer el cambio de valores del arreglo en una posición después de que se 
                cumpla la condición 'j > j + 1'. Es por esto que el cambio lo hacemos a la variable j + 1.
                */
                swapElements(nums, j, j + 1);
            }
        }
    }
}

void ordenaMerge(vector<int> &nums, int low, int high)
{

    int mid = (low + high) / 2;
    if (low < high)
    {
        ordenaMerge(nums, low, mid);
        ordenaMerge(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

void merge(vector<int> &nums, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    vector<int> aux;
    // Unir los dos subarreglos en el arreglo aux.
    while (i <= mid && j <= high)
    {
        if (nums[i] < nums[j])
        {
            aux.push_back(nums[i]);
            i++;
        }
        else
        {
            aux.push_back(nums[j]);
            j++;
        }
    }

    // Insertar todos los valores restantes desde i a mitad en aux.
    while (i <= mid)
    {
        aux.push_back(nums[i]);
        i++;
    }

    // Insertar todos los valores restantes desde j a fin en aux.
    while (j <= high)
    {
        aux.push_back(nums[j]);
        j++;
    }

    // Asignar los valores ordenados que yacen en aux hacia el arreglo a.
    for (i = low; i <= high; i++)
    {
        nums[i] = aux[i - low];
    }
}

int busqSecuencial(vector<int> &nums, int n)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (n == nums[i])
        {
            // devuelve el indice donde esá ubicado el elemento 'n'.
            return i;
        }
    }

    // Devuelvme -1 si el valor 'n' no se encuentra en el vector.
    return -1;
}

/* En esta función el arreglo ya debe de venir sorteado. */
int busqBinaria(vector<int> &nums, int min, int max, int num)
{

    // Regresa el index de un elemento de un arreglo ordenado. Se busca de manera recursiva.

    if (max >= min)
    {
        int key = (min + max) / 2;

        if (num == nums[key])
        {
            return key;
        }

        else if (num <= nums[key])
        {
            max = key - 1;
            return busqBinaria(nums, min, max, num);
        }

        else if (num >= nums[key])
        {
            min = key + 1;
            return busqBinaria(nums, min, max, num);
        }
    }
    return -1; //no se encontró valor
}
