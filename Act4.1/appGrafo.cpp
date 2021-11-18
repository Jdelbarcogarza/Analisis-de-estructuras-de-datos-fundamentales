#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "Node.h"
using namespace std;

int timeCounter;
vector<bool> dfsVisited;

void BFS(vector<vector<Node<int>>> &adjList, int rootNode);
void DFS(vector<vector<Node<int>>> &adjList, int rootNode);
void DFSVisit(vector<vector<Node<int>>> &adjList, vector<Node<int>>&adjNodes);
void loadGraph(vector<vector<Node<int>>> &adjList, int nodeAmount, int edgeAmount, string filename);
void printList(vector<vector<Node<int>>> &adjList, int nodeAmount);

int main(void){

    string filename = "in2.txt";
    
    fstream in(filename);
    int nodeAmount, edgeAmount, rootNode; // characteristic variables of graph
    
    in >> nodeAmount >> edgeAmount >> rootNode;

    in.close();

    // crear lista de adyacencia con nodeAmpount espacios.
    vector<vector<Node<int>>> adjList(nodeAmount + 1); // lo hago +1 por si llega a existir un nodo 0.

    loadGraph(adjList, nodeAmount, edgeAmount, filename);
    
    printList(adjList, nodeAmount);

    //cout <<"here: " << adjList[0].size();

    
    cout << "BFS: ";
    BFS(adjList, rootNode);
    
    cout << "DFS: ";
    
    // set all nodes to not visited
    for (unsigned int i = 0; i < adjList.size(); i++){
        dfsVisited.push_back(false);   
    }

    DFS(adjList, rootNode); 
    
}
// Para DFS
// in1: 1 2 4 5 3
// in2: 1 3 5 6 7 8 9 10 4 2

void DFSVisit(vector<vector<Node<int>>> &adjList, vector<Node<int>>&adjNodes){

    timeCounter = timeCounter + 1;

    // itera sobre la lista que pasaste como parámetro
    for (unsigned int i = 0; i < adjNodes.size(); i++){
    //cout << "who" << adjNodes[i].getDestination() << endl;
    
        // si el primer nodo de esa lista de adyacencia no ha sido visitado
        if (dfsVisited[adjNodes[i].getDestination()] == false){
            // imprime el nodo
            cout << adjNodes[i].getDestination() << " ";

            // marcalo como visitado
            dfsVisited[adjNodes[i].getDestination()] = true;

            // ahora ese nodo lo debes pasar para buscar el siguiente conectado a ese.
            DFSVisit(adjList, adjList[adjNodes[i].getDestination()]);
        } 
    }

    return;
    // pasas la lista de vecinos del nodo siguiente, no los nodos vecinos del actual nodo
    // esto ni se está corriendo creo
    DFSVisit(adjList, adjList[adjNodes[0].getDestination()]);
    
    timeCounter = timeCounter + 1;
}

void DFS(vector<vector<Node<int>>> &adjList, int rootNode){

    timeCounter = 0;
    
    if (dfsVisited[adjList[rootNode][0].getOrigin()] == true){
      return;
    }

    // imprime el primer nodo que visitaste
    cout << adjList[rootNode][0].getOrigin() << " ";

    for (unsigned int currentNode = rootNode; currentNode < adjList.size()-1; currentNode++){
      //cout << currentNode << endl;
            
            // si no hemos visitado el nodo. Lo visitamos con DFS-Visit
            // adjList[currentNode][0].getOrigin() -> 1
        if (dfsVisited[adjList[currentNode][0].getOrigin()] == false){
            
            // ponemos el nodo fuente como ya visitado
            dfsVisited[adjList[rootNode][0].getOrigin()] = true;

            // pasamos la lista entera y la lista de adjacencia del currentNode 
            DFSVisit(adjList, adjList[currentNode]);
        }       
    }
      // ponemos el nodo fuente como ya visitado
        dfsVisited[adjList[rootNode][0].getOrigin()] = true;
    
    // edge case para casos donde no hay un nodo conectado
    for (unsigned int i = 0; i < dfsVisited.size(); i++){
        
        // si no haz visitado ese nodo. Hazle dfs
        if (dfsVisited[i] == false && adjList[i].size() != 0){
            // hazle DFS a ese nodo
            DFS(adjList, i);
        }
    }
}

void BFS(vector<vector<Node<int>>> &adjList, int rootNode){

    queue<int> gray; // processed nodes
    vector<bool> visited;
    int currentNode;
    
    // set all nodes to not visited
    for (unsigned int i = 0; i < adjList.size(); i++){
        visited.push_back(false);    
    }

    // aqui se hace un push del nodo en el que estamos
    gray.push(adjList[rootNode][0].getOrigin());
    
    // el nodo inicial lo marcas como visitado
    visited[rootNode] = true;

    // OJO: EL LOOP PODRÍA SER SIZE() - 1 PORQUE NO ESTAMOS CONTANDO EL CERO PERO SÍ ESTÁ AHÍ. CUIDADO

    while(!gray.empty()){

        currentNode = gray.front();
        gray.pop();

        // OUTPUT
        cout << currentNode;

        for (unsigned int adjNode = 0; adjNode < adjList[currentNode].size(); adjNode++){

            //cout << adjList[currentNode][adjNode].getDestination() << " ";
            
            // si ya está visitado ese nodo, pasa al siguiente.
            if (visited[adjList[currentNode][adjNode].getDestination()] == true){
                continue;
                
            } else {
                // si no lo haz visitado. Marcalo como visitado
                visited[adjList[currentNode][adjNode].getDestination()] = true;
            }

            // add nodes attached to currentNode
            gray.push(adjList[currentNode][adjNode].getDestination());

        }
            cout << " ";   
    }
    cout << endl;
}


void loadGraph(vector<vector<Node<int>>> &adjList, int nodeAmount, int edgeAmount, string filename){

    fstream in(filename);

    int pointA, pointB, edgeWeight;

    // we read input to ignore first line.
    in >> pointA >> pointB >> edgeWeight;

    string s;
    // here we start from one bc we want to ignore the 0 index that is empty, but this will not
    // always be the case.
    for (int i = 0; i < edgeAmount; i++){
        
        in >> pointA >> pointB >> edgeWeight;

        adjList[pointA].push_back(Node<int>(pointA, pointB, edgeWeight));

        // PREGUNTALE AL PROFE SI ESTO ESTÁ BIEN.
        /* EN TEORÍA ES UN GRAFO NO DIRIGIDO, POR LO QUE LOS NODOS PUEDEN INTERCONECTARSE POR ESO
        LA LÍNEA  DEBAJO ES VÁLIDA*/
        //adjList[pointB].push_back(Node<int>(pointB, pointA, edgeWeight));
    }
}

void printList(vector<vector<Node<int>>> &adjList, int nodeAmount){

    for (unsigned int i = 0; i < adjList.size(); i++){

        // don't print non-existing nodes.
        if (adjList[i].size() == 0){
            continue;
        }

        cout << "[" << i << "]" << "--> ";
        for (unsigned int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j].getDestination() << "|" << adjList[i][j].getWeight() << "--> ";
        }

        cout << "END" << endl;

    }

}
