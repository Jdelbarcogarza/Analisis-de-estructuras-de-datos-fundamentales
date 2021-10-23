
#include "Node.h"
using namespace std;
class BST{

    private: 
        Node *root;

    public:

        BST();
        ~BST();

        void insert(string data, int numAccesos);
        void destroy(Node* root);
        //void ancestors(int data);
        void print5greatest();
        int height();
        
 
};



vector<string> greatestIP;
vector<int> greatestAccess;

void fiveGreatest(Node* root){
    
    if( root != nullptr){

        fiveGreatest(root->getRight());
        greatestIP.push_back(root->getData());
        greatestAccess.push_back(root->getNumAccesos());
        fiveGreatest(root->getLeft());
    }
}

void BST::print5greatest(){

    if( root != nullptr){

        fiveGreatest(root->getRight());
        greatestIP.push_back(root->getData());
        greatestAccess.push_back(root->getNumAccesos());

        fiveGreatest(root->getLeft());
    }

    for (int i = 0; i < 5; i++){ 
        cout << i+1 << ". " <<"IP: " << greatestIP[i] << " " << "Numero Accesos: " << greatestAccess[i] << endl;
    }

}


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

void BST::insert(string data,int numAccesos){

    Node* current = root;

    // father es el papá del nodo hoja que queremos insertar.
    Node* father = nullptr;

    while(current != nullptr){
        
        // conforme vamos bajando, el padre va a ser actual
        father = current;

        // condicional para ver si se va a la derecha o izquierda

        if(current->getNumAccesos() > numAccesos){
          current = current->getLeft();
        }
        else{
          current = current->getRight();
        }
      
    }

    // si el arbol está vacío
    if (father == nullptr){
        root = new Node(data,numAccesos);
    } else{

        if (father->getNumAccesos() > numAccesos){

            father->setLeft(new Node(data,numAccesos));
        } else if (father->getNumAccesos() <= numAccesos){
            father->setRight(new Node(data,numAccesos));
        }
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

