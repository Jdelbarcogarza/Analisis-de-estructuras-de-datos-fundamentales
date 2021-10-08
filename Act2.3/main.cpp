#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "DoubleLinkedList.h"
using namespace std;


void fillDLL(DoubleLinkedList<string> &uoList, string fileName);
float sortingValue(DoubleLinkedList<string> &unorderedList, int index);
void fillSortedFile(DoubleLinkedList<string> &list);
void fillFile(DoubleLinkedList<string> &list ,int indiceInicial, int indiceFinal);
int busquedaSecuencial(DoubleLinkedList<string> &logger, int key);
void fillRangeFile(DoubleLinkedList<string> &list);



int main(){

    //Declaramos variables iniciales
    string rangoin, rangofi;
    
    int indexin, indexfi, numRangoIn, numRangoFi;

    // lista que almacenará todo el log del logger de la bitácora.
    DoubleLinkedList<string> unorderedList;

    // Llenamos la lista con los logs de la bitácora
    fillDLL(unorderedList, "bitacora.txt");
    

    unorderedList.insertionSort();
    cout << "Los datos han sido ordenados\n";

    // llenamos archivo ya sorteado para ahorrar tiempo en pruebas
    fillSortedFile(unorderedList);


    cout << "*Solo se toma la primera parte de la IP para brindar un mejor servicio :)\n";
    cout << "Escribe el valor de inicio para tu rango de busqueda de la IPs: (Ejemplo 100) ";
    
    
    getline(cin, rangoin);
    numRangoIn = stoi(rangoin);
    indexin = busquedaSecuencial(unorderedList, numRangoIn);

    cout << "Escribe el valor final para tu rango de busqueda de IPs: (Ejemplo 300) ";
    getline(cin, rangofi);
    numRangoFi = stoi(rangofi) +1;

    indexfi = busquedaSecuencial(unorderedList, numRangoFi);
    

    fillFile(unorderedList, indexin, indexfi);
    
    unorderedList.deleteAll();
    
    cout << "done\n";

    return 0;
}

/*
Función que toma los indices con la busqueda correcta y llenan los datos en el archivo FINAL
*/
void fillFile(DoubleLinkedList<string> &list, int indiceInicial, int indiceFinal)
{

    ofstream myfile ("ListaFinal.txt");
    if (myfile.is_open()){
        for(int i = indiceInicial; i <= indiceFinal -1; i++)
        {
            myfile << list.read(i) << endl;
        }
        cout << "¡Se guardaron los datos en el archivo!" << endl;
        myfile.close();
    }  
    
}

/* Función que guarda los datos ordenados en un archivo de bitácoraOrdenada*/
void fillSortedFile(DoubleLinkedList<string> &list){

    ofstream myfile ("bitacoraOrdenada.txt");
    if (myfile.is_open()){
        for(int i = 0; i <= list.getSize(); i++)
        {
            myfile << list.read(i) << endl;
        }
        cout << "¡Se guardaron los datos en el archivo!" << endl;
        myfile.close();
    }

}

/*
Recibe como parámetro la DLL como referencia para que así sea más eficiente todo.
*/
void fillDLL(DoubleLinkedList<string> &unorderedList, string fileName)
{

    // Variable que guarda cada renglon 
    string s;
    ifstream in(fileName);
    
    while (getline(in, s))
    {
        // insertamos al inicio de la lista cada uno de los logs de la bitácora.
        /*LO HICIMOS DE ESTA MANERA PORQUE LA INSERCIÓN ES O(1), mientras que al insertLast()
        siempre iba a ser O(n) */
        unorderedList.push(s);
    }
}


int busquedaSecuencial(DoubleLinkedList<string> &logger, int key){

    for (int i = 0; i < logger.getSize(); i++){ //Recorremos vector

        /*TODO: Aqui hay que revisar en dónde empiezan las IPs en cada log, si en el lugar
        15 o 16. Usa tus otras funciones para encontrarlo. */
        if (logger.read(i)[15] == ' '){
            if (stoi(logger.read(i).substr(16,19)) == key){

            return i;
            }
        }
        else if(stoi(logger.read(i).substr(15,18)) == key){
            return i;
        }
    }
    cout << "Es fecha no esta en el rango de datos" << endl;
  return -1;
}


/* Función que guarda los datos ordenados en un archivo de ListaFinal para después utilizarse para guardar los datos dentro del rango que el usuario ingresó*/
void fillRangeFile(DoubleLinkedList<string> &list){

    ofstream myfile ("ListaFinal.txt");
    if (myfile.is_open()){
        for(int i = 0; i <= list.getSize(); i++)
        {
            myfile << list.read(i) << endl;
        }
        cout << "¡Se guardaron los datos en el rango ingresado en el archivo!" << endl;
        myfile.close();
    }

}


