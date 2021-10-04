#include <iostream>
#include "LinkedList.h"
#include <string>
#include <fstream>
using namespace std;

int main(void){

    // escribe 1, 2, 3 o 4 en el número dentro de la función "in()".
    ifstream in("1.in");

    LinkedList<int> lista;

        string s;
        int i;
        // Ciclo que lee el arreglo
        while (getline(in, s))
        {
            i = stoi(s);
            lista.addLast(i);
        }

    int option;
    int valor, pos;

    do {

        
        cout << "\nQue quieres hacer con la siguiente linked list?\n";

        lista.print();
        cout << endl;

        cout << "1) insertar elemento\n";
        cout << "2) borrar elemento\n";
        cout << "3) leer elemento\n";
        cout << "4) cambiar elemento\n";
        cout << "5) salir\n";
        cout << endl;

    
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "dime el valor que quieres insertar\n";
            cin >> valor;

            cout << "en que posicion lo quieres insertar (de 0 a n-1)\n";
            cin >> pos;

            lista.create(valor, pos);
            cout << "Lista actualizada\n";
            lista.print();

            break;

            case 2:
                cout << "dime la posicion del elemento que quieres eliminar\n";
                cin >> pos;

                lista.del(pos);

                cout << "Lista actualizada\n";
                lista.print();
                break;
            case 3:
                cout << "Posicion del elemento quieres leer de la lista\n";

                cin >> pos;

                cout << "Aqui esta tu numero: " << lista.read(pos) << endl;
                break;
            case 4:
                cout << "posicion del elemento que quieres cambiar\n";
                cin >> pos;

                cout << "que valor quieres insertar en la posicion (" << pos << ")\n";
                cin >> valor;

                lista.update(valor, pos);

                cout << "Lista actualizada\n";
                lista.print();
                break;
        default:
            break;
        }

    }while (option != 5);

    cout << "Saliste del programa\n";

    /*
    int archivo;

    string archivos[] = {"1.in", "2.in", "3.in", "4.in"};

    cout << "\nEscriba el # de archivo:\n";
    cout << "1) ints\n";
    cout << "2) strings\n";
    cout << "3) chars\n";
    cout << "4) long\n";
    cout << endl;

    cout << "Numero de archivo: ";
    cin >> archivo;
    cout << endl << endl;

    ifstream in(archivos[archivo-1]); // agarra un archivo diferente cada iteración.
    */
/*
    if (archivo == 1){

        LinkedList<int> lista;

        string s;
        int i;
        // Ciclo que lee el arreglo
        while (getline(in, s))
        {
            i = stoi(s);
            lista.addLast(i);
        }

        cout << "Tamano inicial de la lista: " << lista.getSize() << endl;

        lista.create(80, 3);
        lista.print();

        lista.del(2);
        lista.print();

        lista.update(90,4);
        lista.print();

        cout << "Leer valor en posicion 4: " << lista.read(4) << endl;

        cout << "Tamano de la lista final: " << lista.getSize();

    } else if (archivo == 2){

        LinkedList<string> lista;
    } else if (archivo == 3){
        LinkedList<char> lista;
    } else if (archivo == 4){
        LinkedList<long> lista;
    }

*/

    

}