#include <iostream>
#include "priority_queue.h"

using namespace std;

int main(void){

    priority_queue list;

    int A[10] = {16,14,10,8,7,9,3,2,4,1};

    for (int i = 0; i < 10; i++){
        list.push(A[i]);
    }


    /*
    Como manejamos un priority queue con 3 o menos elementos.
    Como haremos para que el número más grande siempre esté al principio.
    MAX heapify se hace con un arreglo ya establecido. No cuando se le van insertando valores-
    recursivamente hace que los valores vayan flotando hacia arriba o hacia abajo.
    */

   for (int i = 0; i < 10; i++){
   list.pop();
   }

    list.print();

}