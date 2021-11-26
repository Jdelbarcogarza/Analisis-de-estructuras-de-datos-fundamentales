#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "Entry.h"
#include "BST.h"
using namespace std;

void readFile(vector<Entry> &list, string filename);
void print5greatest(vector<Entry> &list);
string clearEntry(string s);

int main() {

    // vector con objetos. Cada objeto contiene su IP y su número de accesos.
    vector<Entry> list;
    BST tree;

    readFile(list, "bitacora.txt");

    cout << "Numero IPS: " << list.size() << endl;

    for (unsigned int i = 0; i < list.size(); i++){
        tree.insert(list[i].getIP(), list[i].getNumAccesos());
    }

    cout << "Altura del arbol: " << tree.height() << endl;

    cout << "Top 5 IPs con mas accesos" << endl;
    tree.print5greatest();

}

void readFile(vector<Entry> &list, string filename){

    fstream in(filename);
    string IP;
    bool newIP;

    while(getline(in, IP)){

        newIP = true;

        // Obtenemos la pura IP de toda la línea
        IP = clearEntry(IP);

        for (unsigned int i = 0; i < list.size(); i++){

            if (IP.compare(list[i].getIP()) == 0){

                list[i].increaseNumAccesos();

                // Si ya se hizo match con alguna IP, se para el programa y no se crea un nuevo entry para agregar a la lista.
                newIP = false;
                break;
            }
        }

        // revisar si se debe de crear un nuevo objeto entry con una nueva IP para agregarlo al vector.
        if (newIP == true){
            Entry newObj = Entry(IP);
            list.push_back(newObj);
        }

    }

}

string clearEntry(string s){

    // Hacer string slicing y solo sacar la IP.
    int firstSpace, secondSpace, thirdSpace;

    firstSpace = s.find(' ');
    //cout << "Espacio 1 should be 3: " << firstSpace << endl;
    secondSpace = s.find(' ', firstSpace + 1);
    //cout << "Espacio 2 should be 5:" << secondSpace << endl;
    thirdSpace = s.find(' ', secondSpace + 1);
    //cout << "Espacio 3 "<< thirdSpace << endl;

    // Guardamos de donde comienza la IP hasta el final del string
    s = s.substr(thirdSpace+1);

    // Ahora solo conseguimos la IP son contar el puerto.
    s = s.substr(0, s.find(":"));

    // Regresamos la pura IP
    return s;

}
