#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(void){

    LinkedList<int> lista;

    for (int i = 10; i < 20; i++){

        lista.addLast(i);
    }

    cout << "\n\n";
    cout << "lista original\n";
    lista.print();
    cout << endl;

    // Función de insertAt de la linkedList
    cout << "Insertar numero:\n";
    lista.create(4000,4);
    lista.print();
    cout << endl;


    cout << "Leer valor de posicion 5: ";
    cout << lista.read(5) << endl;
    cout << endl;

    cout << "Actualizar valor en posicion 2 por un 500:\n";
    lista.update(500,2);
    lista.print();
    cout << endl;

    cout << "Borrar valor en posicion 4:\n";
    lista.del(4);
    lista.print();
    cout << endl;

    lista.deleteAll();

}