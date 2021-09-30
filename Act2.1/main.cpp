#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(void){

    LinkedList<int> lista;

    for (int i = 10; i < 20; i++){

        lista.addLast(i);
    }

    // TODO: CORREGIR PRINT FUNCTION. TERMINA APUNTANDO AL FINAL DE LA FUNCIÓN POR ESO NO APARECE LA LISTA
    cout << "lista original\n";
    lista.print();

    // Función de insertAt de la linkedList
    lista.create(50,5);
    lista.print();

    cout << lista.read(5) << endl;
    //lista.print();

    lista.update(100,5);
    //lista.print();

    lista.del(2);
    //lista.print();

    

}