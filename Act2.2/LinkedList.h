#ifndef __LinkedList_h__
#define __LinkedList_h__

#include "Node.h"


template <class T>
class LinkedList{

    private:
        Node<T>* head;
        int size;

    public:
        LinkedList(); // constructor
        ~LinkedList(); // destructor
        void addFirst(T data);
        void addLast(T data);
        void deleteAll();

        // Función que inserta un elemento en la linked list
        void create(T data, int index);

        // TODO: Add Operator overload '[]'
        T read(int index);

        // Función que actualiza el valor de un elemento en una posición determinada.
        void update(T data, int index);

        // Función que elemina un elemento determinado de la lista dada una posición determinada.
        void del(int index);

        int getSize();
        void print();
};

template<class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

template<class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}

template<class T>
void LinkedList<T>::addFirst(T data){
    
    head = new Node<T>(data, head);
    size = size + 1;

}

template<class T>
void LinkedList<T>::addLast(T data){
    
    /* Aquí head apunta siempre o a NULL si no hay elementos en la lista, o a la referencia del nodo siguiente.
    Por eso se llama "current" la variable. */
    Node<T>* current = head;

    if(size == 0){
        addFirst(data);
        return;
    }

    // recorremos la lista para llegar hasta el final.
    while(current->getNext() != nullptr){
        current = current->getNext();
    }

    // insertamos Nodo en el último lugar.
    current->setNext(new Node<T>(data));
    size = size + 1;

}

template<class T>
void LinkedList<T>::deleteAll(){
    Node<T>* current = head;

    while (head != nullptr)
    {
        head = head->getNext(); // se dirige al siguiente Nodo
        delete current; // usamos 'delete' para liberar la memoria dinámica en el anterior
        current = head; // se asigna head al Nodo actual.
    }
    size = 0;
}

template<class T>
void LinkedList<T>::create(T data, int index){

    // mensaje de error si no se puede insertar en esa posición "index" el valor "data"
    if (index > size){
        std::cout << "No hay suficientes elementos para insertar el valor " << data << " en la posicion: " << index << std::endl;
        return;
    } else if (index < 0){
        std::cout << "Esa posicion no existe" << std::endl;
        return;
    }

    // Si se quiere insertar en la primera posición utilizamos la función que ya tenemos.
    if (index == 0){
        addFirst(data);
        return;
    }

    // Variable que insertará en la linked list el valor "data". Una vez se hayan traversado "index" elementos.
    int pivot = 0;

    Node<T>* current = head;

    // Atravesamos la linked list hasta llegar a la posición deseada-1 para crear donde queremos el nuevo nodo.
    for (int i = 0; i < index - 1; i++){
        current = current->getNext();
    }

    // El nuevo nodo apunta a donde apuntaba el nodo anterior.
    Node<T>* newNode = new Node<T>(data, current->getNext());

    // El nodo anterior apunta al nuevo nodo creado
    current->setNext(newNode);

    // incrementamos el tamaño de la lista
    size = size + 1;
}

/* Función que devuelve el dato de un elemento de la lista dada la ubicación de este.*/
template <class T>
T LinkedList<T>::read(int index){

    if(index > size - 1 || index < 0){

        std::cout << "Esa posicion no existe" << std::endl;
        return -1;
    }
    // Variable que insertará en la linked list el valor "data". Una vez se hayan traversado "index" elementos.
        int pivot = 0;
        Node<T>* current = head;
    // Atravesamos la linked list hasta llegar a la posición deseada-1 para ocupar el índice exácto de la lista
    for (int i = 0; i < index; i++){
        current = current->getNext();
    }
    return current->getData();
}


template <class T>
void LinkedList<T>::update(T data, int index){

    if(index > size - 1 || index < 0){
        std::cout << "Esa posicion no existe" << std::endl;
        return;
    }

    // Variable que insertará en la linked list el valor "data". Una vez se hayan traversado "index" elementos.
    Node<T>* current = head;

    // Atravesamos la linked list hasta llegar a la posición deseada para ocupar el índice exácto de la lista
   for (int i = 0; i < index; i++){
        current = current->getNext();
    }

    // Actualizamos el valor del elemento ubicado en la posición "index";
    current->setData(data);
}

template <class T>
void LinkedList<T>::del(int index){

    if(index > size - 1 || index < 0){

        std::cout << "Esa posicion no existe" << std::endl;
        return;
    }

    // Si quiere borrar la cabeza
    if(index == 0){

        delete head;

        // cambiamos la cabeza al siguiente nodo
        head = head->getNext();
        return;
    }

    // Variable que insertará en la linked list el valor "data". Una vez se hayan traversado "index" elementos.
    int pivot = 0;
    Node<T>* current = head;
    
    // Debemos tener referencia del nodo anterior para contectarlo con el ->getNext()->getNext()
    Node<T>* previousNode;

    // Atravesamos la linked list hasta llegar a la posición deseada para ocupar el elemento anterior al dado.

    for (int i = 0; i < index; i++){
        previousNode = current;
        current = current->getNext();
    }

    previousNode->setNext(current->getNext());

    // Liberamos memoria del nodo eliminado
    delete current;
    
}

template <class T>
void LinkedList<T>::print(){
    
    Node<T>* current = head;

    std::cout << "head --> ";
    while(current != nullptr){
        std::cout << current->getData() << " --> ";
        current = current->getNext();
    }
    std::cout << "NULL" << std::endl;
}

template <class T>
int LinkedList<T>::getSize(){

    return size;
}

#endif