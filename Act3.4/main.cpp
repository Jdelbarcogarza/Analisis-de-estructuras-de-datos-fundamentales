#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "Entry.h"
using namespace std;

void readFile(vector<Entry> &list, string filename);
string clearEntry(string s);

int main() {
  
    // vector con objetos. Cada objeto contiene su IP y su número de accesos.
    vector<Entry> list;

    readFile(list, "bitacora.txt");

    cout << list.size() << endl;

    /*
    for (unsigned int i = 0; i < list.size(); i++){
        cout << "IP: " << list[i].getIP() << " #Accesos: " << list[i].getNumAccesos() << endl;
    }
    */

}

void readFile(vector<Entry> &list, string filename){

    fstream in(filename);
    string IP;
    bool newIP = true;

    while(getline(in, IP)){
        
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
        if (newIP){
            Entry newObj = Entry(IP);
            list.push_back(newObj);
        }

    }

}

string clearEntry(string s){

    // Hacer string slicing y solo sacar la IP.
    int firstSpace, secondSpace, thirdSpace;

    firstSpace = s.find(' ');
    secondSpace = s.find(' ', firstSpace + 1);
    thirdSpace = s.find(' ', secondSpace + 1);
    
    // Guardamos de donde comienza la IP hasta el final del string
    s = s.substr(thirdSpace);

    // Ahora solo conseguimos la IP son contar el puerto.
    s = s.substr(1, s.find(":"));

    // Regresamos la pura IP 
    return s;

}