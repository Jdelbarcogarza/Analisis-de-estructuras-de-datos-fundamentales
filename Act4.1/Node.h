
template <class T>
class Node{


    private:
        T data;
        T weight;
        Node<T>* next;

    public: 
        Node(T data, T weight); // constructor
        Node(T data, T weight, Node<T>* next); // constructor
        T getData();
        Node<T>* getNext();
        T getWeight();
        void setData(T data);
        void setNext(Node<T>* next);
        void setWeight(T weight);

};


template <class T> // Declaración de tipo 'T'.
Node<T>::Node(T data, T weight){
    this->data = data;
    this->weight = weight;
    this->next = nullptr; // NULL definido en librería std para apuntadores.

}

template <class T>
Node<T>::Node(T data, T weight, Node<T>* next){
    this->data = data;
    this->weight = weight;
    this->next = next;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
T Node<T>::getWeight(){
    return weight;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return next;
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
void Node<T>::setWeight(T weight){
    this->weight = weight;
}