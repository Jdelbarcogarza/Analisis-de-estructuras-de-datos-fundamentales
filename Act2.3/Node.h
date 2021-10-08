#include <string>
using namespace std;

template <class T>
class Node{


    private:
        T data;

        // sorting value que se agrega al nodo.
        float sv;
        Node<T>* next;
        Node<T>* previous;


    public: 
        Node(T data); // constructor
        Node(T data, Node<T>* next, Node<T>* previous); // constructor
        
        //getters
        T getData();
        Node<T>* getNext();
        Node<T>* getPrevious();
        
        //setters
        void setData(T data);
        void setNext(Node<T>* next);
        void setPrevious(Node<T>* previous);
        
        float getSV();
        void setSV(float sv);

        // este T data ya sabemos que es string
        float sortingValue(T data){

            // Variable donde guardaremos cada log y ala que le haremos el string slicing para sacar la IP.
            string log;
            float key;
            int firstDot, secondDot;
            
            // guardamos todo el log
            log = data;
            
            // si el caracter en la posicion 15 es un espacio
            if (log[15] == ' '){
                // la IP se comienza a cortar a partir de la posicion 16 del string
                // actualizamos string de log para que nos devuelva toda la IP el método.
                log = log.substr(16);

                /* COMO SE SORTEA SIN CONTAR EL PUERTO, el caracter que debemos encontrar es ':'
                Si contaramos con el puerto, entonces buscamos hasta el ' ' */
                log = log.substr(0, log.find(':'));
                // Buscamos la ubicacion de los puntos en la IP
                firstDot = log.find('.');
                secondDot = log.find('.',firstDot+1);

                // Con base a eso recortamos la IP para conseguir el valor que queremos usar para sortear.
                log = log.substr(0, secondDot);
                key = stof(log);
                
                // devolvemos el valor.
                return key;
                // funcion que determina si la IP se sortea antes o después
                //ipWeight(log);

            } else {

                // actualizamos string de log para que nos devuelva toda la IP el método.
                log = log.substr(15);
                // obtenemos la pura IP del substring
                log = log.substr(0, log.find(':'));
                firstDot = log.find('.');
                
                secondDot = log.find('.',firstDot+1);
                log = log.substr(0, secondDot);
                key = stof(log);

                return key;

                }

            }

};

template <class T>
void Node<T>::setSV(float sv){
  this->sv = sv;
}

template <class T>
float Node<T>::getSV(){
  return sv;
}

template <class T> // Declaración de tipo 'T'.
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr; // NULL definido en librería std para apuntadores.
    this->previous = nullptr;
    this->sv = sortingValue(data); // el constructor del nodo ya me da un Sorting value

}

template <class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* previous){
    this->data = data;
    this->next = next;
    this->previous = previous;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}

template <class T>
Node<T>* Node<T>::getPrevious(){
    return previous;
}

template <class T>
void Node<T>::setData(T data){
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}

template <class T>
void Node<T>::setPrevious(Node<T>* previous){
    this->previous = previous;
}