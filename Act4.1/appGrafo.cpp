#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "LinkedList.h"

using namespace std;


void loadGraph(LinkedList<int> adjList[], int nodeAmount, int edgeAmount);

int main(void){

    fstream in("in1.txt");

    int nodeAmount, edgeAmount, rootNode; // characteristic variables
    
    // get n, m and s
    in >> nodeAmount >> edgeAmount >> rootNode;

    // array that will contain the linked lists on each index.
    LinkedList<int> *adjList = new LinkedList<int>[nodeAmount];

    loadGraph(adjList, nodeAmount, edgeAmount);

    int pointA, pointB, edgeWeight;



    // delete used memory
    delete[] adjList;
    return 0;

}

void loadGraph(LinkedList<int> adjList[], int nodeAmount, int edgeAmount){

    adjList[0].addLast(34);
    adjList[0].addLast(3);
    adjList[0].addLast(4);
    adjList[0].addLast(56);

    for (int i = 0; i < 1; i++){
        adjList->print();
    }

}
