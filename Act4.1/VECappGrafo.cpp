#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "LinkedList.h"

using namespace std;


void loadGraph(vector<LinkedList<int>> &adjList, int nodeAmount, int edgeAmount, string filename);
void printAdjList(vector<LinkedList<int>> &adjList, int nodeAmount);

int main(void){

    string filename = "in1.txt";

    fstream in(filename);

    int nodeAmount, edgeAmount, rootNode; // characteristic variables
    
    // get n, m and s
    in >> nodeAmount >> edgeAmount >> rootNode;

    /* SOLO NECESITO 4 NODOS PORQUE LAS COMBINACIONES YA SE DIERON EN TODOS LOS NODOS ANTERIORES
    COMO QUIERA CHECARLO CON EL PROFE.*/
    nodeAmount = nodeAmount + 1;

    // array that will contain the linked lists on each index.
    /* Since we want to start adding numbers from the indexes that we have, (in this case we don't have
    zero) we just print */
    //LinkedList<int> *adjList = new LinkedList<int>[nodeAmount+1];
    vector<LinkedList<int>> adjList(nodeAmount); // initialize vector with nodeAmount indexes;

    int pointA, pointB, edgeWeight;

    

    loadGraph(adjList, nodeAmount, edgeAmount, filename);
    

    printAdjList(adjList, nodeAmount);

    // delete used memory
    delete &adjList;
    return 0;

}

void loadGraph(vector<LinkedList<int>> &adjList, int nodeAmount, int edgeAmount, string filename){

    fstream in(filename);


    int pointA, pointB, edgeWeight;

    // we read input to ignore first line.
    in >> pointA >> pointB >> edgeWeight;

    string s;
    // here we start from one bc we want to ignore the 0 index that is empty, but this will not
    // always be the case.
    for (int i = 0; i < edgeAmount; i++){
        
        in >> pointA >> pointB >> edgeWeight;
        
        cout << pointA << " " << pointB << " " << edgeWeight << endl;
        adjList[pointA].addFirst(pointB, edgeWeight);

        // PREGUNTALE AL PROFE SI ESTO ESTÁ BIEN.
        /* EN TEORÍA ES UN GRAFO NO DIRIGIDO, POR LO QUE LOS NODOS PUEDEN INTERCONECTARSE POR ESO
        LA LÍNEA  DEBAJO ES VÁLIDA*/
        adjList[pointB].addFirst(pointA, edgeWeight);
        
    }

}

void printAdjList(vector<LinkedList<int>> &adjList, int nodeAmount){

    // ¿Por qué en adjList[0].print() no hay elementos?
    for (int i = 0; i < nodeAmount; i++){
        // si la lista está vacía no imprimas 
        if (adjList[i].getSize() == 0){
            continue;
        }
        cout << "[" << i << "] --> ";
        adjList[i].print();
    }

}
