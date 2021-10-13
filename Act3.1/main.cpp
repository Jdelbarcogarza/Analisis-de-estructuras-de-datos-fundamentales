#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"

using namespace std;

void fillTree(BST &tree, string filename);


int main(void){


    BST tree;

    int option;

    cout << "Que archivo quieres probar?\n1) 01.in\n2) 02.in\n3) 03.in\n4) 04.in" << endl;
    cin >> option;
    cout << endl;

    switch (option)
    {
    case 1:
    
        // Se llena la estructura de datos con su respectivo archivo.
        fillTree(tree, "01.in");    
        break;

    case 2:

        fillTree(tree, "02.in");    
        break;

    case 3:

        fillTree(tree, "03.in");
        break;
    
    case 4:
        fillTree(tree, "04.in");

    default:

        fillTree(tree, "01.in");
        break;
    }

    cout << "preorder: ";
    tree.visit(1);
    cout << endl;
    
    cout << "inorder: ";
    tree.visit(2);
    cout << endl;

    cout << "postorder: ";
    tree.visit(3);
    cout << endl;

    cout << "level by level: \n";
    tree.visit(4);
    cout << endl;

    int ancestor, whatLevel;

    cout << "Altura: " << tree.height() << endl;

    cout << "De que numero quieres checar el ancestro?" << endl;
    cin >> ancestor;
    cout << "Ancestros: ";
    tree.ancestors(ancestor);
    cout << endl;


    cout << "De que numero quieres checar su nivel?" << endl;
    cin >> whatLevel;
    cout << "Nivel: " << tree.whatlevelamI(whatLevel) << endl;

    

    tree.~BST();

}

/* Función que llena la estrucutra de datos de una archivo con sus elementos
   Parámetros:
    {Estrucuta de datos} nombre de la estructura de datos
    {string} nombre del archivo de texto.*/
void fillTree(BST &tree, string filename){

    ifstream in(filename);
    string s;
    int num;

    while(getline(in, s)){

        num = stoi(s);
        tree.insert(num);
    }

}