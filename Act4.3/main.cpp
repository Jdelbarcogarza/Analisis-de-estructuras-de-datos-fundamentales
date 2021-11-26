#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Node.h"
using namespace std;

string obtenerIpOrigen(string s);
string obtenerIpDestino(string s);
int busqBinaria(vector<vector<Node>> &adjList, int min, int max, int num);

void loadGraph(vector<vector<Node>> &adjList, int nodeAmount, int edgeAmount, string filename);
void printList(vector<vector<Node>> &adjList, int nodeAmount);
int conseguirPeso(string s);
void insertSearch(vector<vector<Node>> &adjList, string origen, string destino);
void imprimirAdjList(vector<vector<Node>> &adjList);
void nodeGrades(vector<vector<Node>> &adjList, vector<int> &grades);


int main(void){

    string filename = "bitacoraACT4_3.txt";

    fstream in(filename);

    int nodeAmount, edgeAmount;
    in >> nodeAmount >> edgeAmount;

    in.close();

    vector<vector<Node>> adjList(nodeAmount);

    loadGraph(adjList, nodeAmount, edgeAmount, filename);

    cout << "Amount of IP addresses: " << adjList.size() << endl;

    // vector que guarda los grados de todos los nodos
    vector<int> grades(nodeAmount);

    nodeGrades(adjList, grades);

    cout << "\nTASK... DONE!\n";

}

void nodeGrades(vector<vector<Node>> &adjList, vector<int> &grades){

  int greatest = 0;

  vector<int> top;

  int topVal = 0;

  for (unsigned int currentNode = 0; currentNode < adjList.size(); currentNode++){
    //cout << "pos: " << i << " es de grado " << adjList[i].size() - 1 << endl;
    grades[currentNode] = adjList[currentNode].size() - 1;

    if (grades[currentNode] > topVal){
      top.clear();
      top.push_back(currentNode);
      topVal = grades[currentNode];
    } else if (grades[currentNode] == topVal){
      top.push_back(currentNode);

    }

  }

  cout << "\n--------------BOOT MASTERS--------------" << endl;

  for (unsigned int i = 0; i < top.size(); i++){
  cout << "IP: " << adjList[top[i]][0].getOrigin() << "..........";
  cout << "Nodes to device: " << grades[top[i]] << endl;

  }

}

void loadGraph(vector<vector<Node>> &adjList, int nodeAmount, int edgeAmount ,string filename){

    fstream in(filename);

    string ip;
    int position;

    // salto basura
    in >> position;
    in >> position;


    // ponemos en el vector 'base' cada uno de los nodos existentes. Actualmente no tienen destinos
    for (int i = 0; i < nodeAmount; i++){

        in >> ip;
        position = i;
        adjList[i].push_back(Node(ip, position));

    }

    // ======================= LLENADO DE ADJLIST ==============================

    string s, ipOriginS, ipDestinationS;

    int ipFirstPart = 0;
    int currentNode; // pivote de a lista de nodos
    int ipOriginI, ipDestinationI;

    int trimObjetivo;

    in.ignore();




    for (int i = 0; i < edgeAmount; i++){

        // leemos todo el renglón
        getline(in, s);

        ipOriginS = obtenerIpOrigen(s);
        ipDestinationS = obtenerIpDestino(s);

        ipOriginI = conseguirPeso(ipOriginS);
        ipDestinationI =conseguirPeso(ipDestinationS);

        // binary search de la ip de origen. Regresar ubicación aproximada de la IP a encontrar
        // encontrar esa ubicación aproximada
        currentNode = busqBinaria(adjList, 0, adjList.size(), ipOriginI);

        // consigo primer0s 3 dígitos de la IP que busco en int
        trimObjetivo = stoi(adjList[currentNode][0].getOrigin().substr(0, adjList[currentNode][0].getOrigin().find('.')));

      // hay que hacer un caso especial cuando el index aproximado es 1
      if (trimObjetivo == 1){
        //cout << "esto hay en ubicación adjList[0]" << adjList[0][0].getOrigin() << endl;

        // vete al primer elemento DIRECTO y de ahí busca secuencial
        currentNode = 0;
        //cout << adjList[0][0].getOrigin() << endl;
      } else{

          while (ipOriginI <= trimObjetivo){

            // ve descendiendo en esa sección de las IPs
            currentNode = currentNode - 1;

            // ve actualizando trim objetivo
            trimObjetivo = stoi(adjList[currentNode][0].getOrigin().substr(0, adjList[currentNode][0].getOrigin().find('.')));

          }

        // suma uno para estar en el primero de esa sección de IPs. y no pasarte
        currentNode = currentNode + 1;
      }

        // hacer búsqueda secuencial en esa sección de ips

        while (ipOriginS != adjList[currentNode][0].getOrigin()){

        // checa hacia arriba
        currentNode = currentNode + 1;

        }

        // hacer el insert en el nodo
        adjList[currentNode].push_back(Node(ipOriginS, ipDestinationS, currentNode));

    }
  cout << "Graph successfully loaded\n" << endl;
}

int busqBinaria(vector<vector<Node>> &adjList, int min, int max, int num)
{

    // Regresa el index de un elemento de un arreglo ordenado. Se busca de manera recursiva.

    if (max >= min)
    {
        int key = (min + max) / 2;

        if (num == stoi(adjList[key][0].getOrigin().substr(0,adjList[key][0].getOrigin().find('.'))))
        {
            return key;
        }

        else if (num <= stoi(adjList[key][0].getOrigin().substr(0,adjList[key][0].getOrigin().find('.'))))
        {
            max = key - 1;

            return busqBinaria(adjList, min, max, num);
        }

        else if (num >= stoi(adjList[key][0].getOrigin().substr(0,adjList[key][0].getOrigin().find('.'))))
        {
            min = key + 1;
            return busqBinaria(adjList, min, max, num);
        }
    }
    return -1; //no se encontró valor
}

/* En esta función el arreglo ya debe de venir sorteado. */


string obtenerIpOrigen(string s){

  int firstSpace = s.find(' ');
  int secondSpace = s.find(' ', firstSpace + 1);
  int thirdSpace = s.find(' ', secondSpace + 1);

  // Guardamos de donde comienza la IP hasta el final del string
    s = s.substr(thirdSpace+1);

    // Ahora solo conseguimos la IP son contar el puerto.
    s = s.substr(0, s.find(":"));

    // Regresamos la pura IP
    return s;

}

string obtenerIpDestino(string s){

  int firstSpace = s.find(' ');
  int secondSpace = s.find(' ', firstSpace + 1);
  int thirdSpace = s.find(' ', secondSpace + 1);
  int fourthSpace = s.find(' ', thirdSpace + 1);

  // Guardamos de donde comienza la IP hasta el final del string
    s = s.substr(fourthSpace+1);

  // Ahora solo conseguimos la IP son contar el puerto.
    s = s.substr(0, s.find(":"));

    // Regresamos la pura IP
    return s;

}

int conseguirPeso(string s){
  string sub = s.substr(0, s.find("."));
  int peso = stoi(sub);
  return peso;
}
