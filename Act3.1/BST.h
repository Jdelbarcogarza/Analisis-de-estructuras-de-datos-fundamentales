#include "Node.h"

class BST{

    private: 
        
        Node *root;

    public:

        BST();
        ~BST();
        bool search(int data);
        void insert(int data);
        void remove(int data);
        void destroy(Node* node);
        void visit(int order);

};


BST::BST(){
    root = nullptr;
}

BST::~BST(){

    destroy(root);
}

void BST::destroy(Node* node){

    // lo primero que se elimina son las hojas.
    // va por niveles
    if (node != nullptr){
        destroy(node->getLeft());
        destroy(node->getRight());
        delete node;
    }

}

bool BST::search(int data){

    Node *current = root;

    while(current != nullptr){
        if(current->getData() == data){
            return true;
        }

        // operador ternario-> (CONDICIÓN) ? ( TRUE que haces si es cierto) : ( FALSE que haces si es falso)
        // solo funciona si la respuesta a la condición regresa un valor u otro. Si no, no jala.
        current = (data < current->getData()) ? current->getLeft() : current->getRight();
    }
    return false;
}

void BST::insert(int data){

    Node* current = root;

    // father es el papá del nodo hoja que queremos insertar.
    Node* father = nullptr;


    while(current != nullptr){
        
        // este if no permite que se inserte un número que ya existe en el BST
        if (current->getData() == data){
            return;
        }

        // conforme vamos bajando, el padre va a ser actual
        father = current;

        // condicional para ver si se va a la derecha o izquierda
        current = (current->getData() > data) ? current->getLeft() : current->getRight();

    }

    // si el arbol está vacío
    if (father == nullptr){
        root = new Node(data);
    } else{

        if (father->getData() > data){

            father->setLeft(new Node(data));
        } else {

            father->setRight(new Node(data));
        }
    }
    
}

int howManyChildren(Node* node){
    int number = 0;
    if (node->getLeft() != nullptr){
        number++;
    }

    if (node->getRight() != nullptr){
        number++;
    }
    
    return number;
}

void BST::remove(int data){

    Node* current = root;
    Node* father = nullptr;
    
    while (current != nullptr && current->getData() != data){

        father = current;
        current = (current->getData() > data) ? current->getLeft() : current->getRight();

    }

    if(current == nullptr){
        return;
    }

    int numeroHijos = howManyChildren(current);
    switch (numeroHijos)
    {
    case 0:

        if(father == nullptr)
        {
            root = nullptr;
        }else{
            if(father->getData() > data)
            {
                father->setLeft(nullptr);
            } else{
                father->setRight(nullptr);
            }
        }

        delete current;
        break;

    case 1:

        if(father == nullptr){
            root = current->getLeft();
            if(current->getLeft() != nullptr){

                root = current->getLeft();
            } else {
                
                root = current->getRight();
            }
        } else {

            if(father->getData() > data){
                if(current->getLeft() != nullptr){

                    father->setLeft(current->getLeft());
                } else {

                    father->setLeft(current->getRight());
                }
            } else {
                if(current->getLeft() != nullptr){

                    father->setRight(current->getLeft());
                } else {

                    father->setRight(current->getRight());
                }
            }
        }

    delete current;
    break;

    case 2:
    break;
    }

}

void visit(int order){

    

}