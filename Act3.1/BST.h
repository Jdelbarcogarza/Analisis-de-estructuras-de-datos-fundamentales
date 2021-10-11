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
        int height();
        void ancestors(int data);
 
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

void preOrder(Node* root){

    if (root != nullptr){

        std::cout << root->getData() << " ";
        preOrder(root->getLeft());
        preOrder(root->getRight());
    }
}

void inOrder(Node* root){

    if( root != nullptr){

        inOrder(root->getLeft());
        std::cout << root->getData() << " ";
        inOrder(root->getRight());
    }

}

void postOrder(Node* root){

    if (root != nullptr){

        postOrder(root->getLeft());
        postOrder(root->getRight());
        std::cout << root->getData() << " ";
    }
}

void byLevel(Node* root){
    
    std::cout << "PENDIENTE";
    /*
    Node* father = root;

    if(root != nullptr){

    std::cout << root->getData() << " ";
    std::cout << root->getLeft()->getData() << " ";
    std::cout << root->getRight()->getData() <<  " ";
    
    }
    byLevel(root->getLeft());
    */
}

/**
 * Desplegará cada uno de los datos almacenados en el BST dependiendo del parámetro en entrada:

    Preorder
    inOrder
    postOrder
    Level by level

    Parámetros:
    Un entero (1-4) indicando la opción del tipo de visita.
*/
void BST::visit(int order){

    switch (order)
    {
    case 1:
        
        preOrder(root);
        break;

    case 2:

        inOrder(root);
        break;
   
    case 3:

        postOrder(root);
        break;

    case 4:

        byLevel(root);
        break;

    default:
        break;
    }

}


/* Función escondida que encuentra la altura de un arbol recursivamente.*/
int bstHeight(Node* root){

    if (root == nullptr){
            return 0;
        }

    int leftHeight = bstHeight(root->getLeft());
    int rightHeight = bstHeight(root->getRight());

    // sumar 1 al lado que tenga más altura
    return  leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

}


/* Función que devuelve la altura de un BST*/
int BST::height(){

    // devolvemos el valor de altura que encontramos con la función.
    return bstHeight(root);
    
}

/* Función que visita los ancestros de un elemento del árbol.*/
void BST::ancestors(int data){


}