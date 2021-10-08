#ifndef __DoubleLinkedList_h__
#define __DoubleLinkedList_h__
#include "Node.h"
//#include <string>
using namespace std;


template <class T>
class DoubleLinkedList{

  private:
  
    int size;
    Node<T>* head;

  public:

    DoubleLinkedList(); //constructor
    ~DoubleLinkedList(); //destructor

     void deleteAll();
    
    //void read(int index);
    void insertLast(T data);
    void push(T data);
    void printList();
    T read(int index);
    int getSize();
    void swap(Node<T>* first, Node<T>* second);
    void insertionSort();
    void bubbleSort(Node<T>* start);
    
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
  this->head = nullptr;
  this->size = 0;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
  deleteAll();
}

template<class T>
void DoubleLinkedList<T>::deleteAll(){
    Node<T>* current = head;

    while (head != nullptr)
    {
        head = head->getNext(); // se dirige al siguiente Nodo
        delete current; // usamos 'delete' para liberar la memoria dinámica en el anterior
        current = head; // se asigna head al Nodo actual.
    }
    size = 0;
}

template <class T>
int DoubleLinkedList<T>::getSize(){
  return size;
}


template <class T>
void DoubleLinkedList<T>::insertLast(T data){
    
    Node<T>* newNode = new Node<T>(data); 
    Node<T>* lastNode = head;
  
    //Checar si la lista esta vacia, y si si hacer ese nodo la cabeza de la lista
    if(head == nullptr){
      head = newNode;
      return;
    }
  
    //Nos movemos al ultimo nodo de la lista
    while(lastNode->getNext() != nullptr){
      lastNode = lastNode->getNext();
    }

    //Asignamos el next del ultimo nodo como el nodo a agregar
    lastNode->setNext(newNode);

    //Asignamos el previous del nodo a agregar como el ultimo nodo
    newNode->setPrevious(lastNode);
  
    size = size + 1;

    return;
  
}


// Función que pone un nuevo elemento al principio de la DLL
template <class T>
void DoubleLinkedList<T>::push(T data){

  // EL CREAR UN NUEVO NODO ME HACE EN AUTOMÁTICO UN NUEVO SORTING VALUE
  Node<T>* newNode = new Node<T>(data);

  // el nuevo nodo apunta en next a la cabeza.
  newNode->setNext(head);

  // el previo del nuevo nodo por default ya es nullptr gracias al constructor.

  // el tail del head ahora apunta al nuevo nodo.
  if (head != nullptr){
    head->setPrevious(newNode);
  }
  //head->setPrevious(newNode);

  // nuevo nodo ahora es head
  head = newNode;

  size = size + 1;

}


// This function prints contents of linked list starting from the given node
template <class T>
void DoubleLinkedList<T>::printList() {
  Node<T>* node = head;

  if(node == nullptr){
  cout<<"NULL";
  } 
  
  while (node != nullptr) {
    
    cout << node->getData() << "\n";
    node = node->getNext();
  }

  cout << "\n" << size;
}


/* Función que devuelve el dato de un elemento de la lista dada la ubicación de este.*/
template <class T>
T DoubleLinkedList<T>::read(int index){

    if(index > size - 1 || index < 0){

        std::cout << "Esa posicion no existe" << std::endl;
        return "sorry :(";
    }
    // Variable que insertará en la linked list el valor "data". Una vez se hayan traversado "index" elementos.
        Node<T>* current = head;
    // Atravesamos la linked list hasta llegar a la posición deseada-1 para ocupar el índice exácto de la lista
    for (int i = 0; i < index; i++){
        current = current->getNext();
    }
    return current->getData();
}

template <class T>
void DoubleLinkedList<T>::swap(Node<T>* first, Node<T>* second){
  

  float aux = first->getSV(); // a = aux
  string value = first->getData();

  first->setSV(second->getSV()); // a = b
  first->setData(second->getData());

  second->setSV(aux); // b = aux
  second->setData(value);

}



template <class T>
void DoubleLinkedList<T>::insertionSort(){

  // Nodos que utilizaremos 
  Node<T>* current = head;
  Node<T>* pivot = nullptr;

  // Atravesamos la lista mientras no hayamos llegado al final.
  while(current != nullptr){

    // pasamos al siguiente nodo
    pivot = current->getNext();

    // hacemos la comparación con los valores que generamos con el valor SV.
    // Este while va a comparar una vez se encuentre algo desordenado para ver si está desordenado 
    // un par de números. Si es así, cambialos de lugar los STRs como los SVs con swap.
    while(pivot != nullptr && pivot->getPrevious() != nullptr && pivot->getSV() < pivot->getPrevious()->getSV())
    {
      // si el dato actual es mayor al de más adelante, los cambiamos
      this->swap(pivot, pivot->getPrevious());
      pivot = pivot->getPrevious();
    }

    // pasamos a la siguiente comparación
    current = current->getNext();
  }

}



#endif