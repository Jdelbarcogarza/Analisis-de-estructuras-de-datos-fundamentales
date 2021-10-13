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
        int whatlevelamI(int data);
 
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

/* Función que indica si existe un valor en el árbol
Retorna: True/False*/
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

void levelNodes(Node* root, int level , int i){

    // Si ya es el nodo hoja
    if (root == nullptr){
        return;
    }

    // si el nivel en el que estamos es igual al de la iteración
    if (level == i){
        std::cout << root->getData() << " ";
        return;
    }

    // imprime los nodos de la izquierda. Solo se corre una vez porque la i != level
    levelNodes(root->getLeft(), level + 1, i);
    levelNodes(root->getRight(), level + 1, i);


}

void byLevel(Node* root){
    
    Node* current = root;
    Node* father = nullptr;

    // Guardamos la altura del árbol
    int height = bstHeight(root);

    for (int i = 0; i < height; i++){
        levelNodes(root, 0, i);
        std::cout << std::endl;
    }

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

/* Función que visita los ancestros de un elemento del árbol.*/
void BST::ancestors(int data){

    // si no se encuentra ese elemento en el árbol no tiene ancestros.
    if (search(data) == false){
        std::cout << "Ese elemento no existe en el arbol. No hay ancestros.\n";
        return;
    }

    Node *current = root;

    while(current->getData() != data){
        
        std::cout << current->getData() << " ";

        // operador ternario-> (CONDICIÓN) ? ( TRUE que haces si es cierto) : ( FALSE que haces si es falso)
        // el pivote se mueve a la izquierda o a la derecha
        current = (data < current->getData()) ? current->getLeft() : current->getRight();
    
    }

}

/* Función para encontrar en qué nivel se encuentra un elemento del árbol*/
int BST::whatlevelamI(int data){

    // El nodo raíz se ubica en el nivel 0.
    int nivel = 0;

    // Si el dato no se encuentra en el árbol
    if (search(data) == false){
        return -1;
    }

    Node *current = root;

    while(current->getData() != data){
        
        // operador ternario-> (CONDICIÓN) ? ( TRUE que haces si es cierto) : ( FALSE que haces si es falso)
        // el pivote se mueve a la izquierda o a la derecha
        current = (data < current->getData()) ? current->getLeft() : current->getRight();

        nivel = nivel + 1;

    }

    return nivel;

}
