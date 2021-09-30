#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void fillVector(vector<string> &logger, string fileName);
void printVector(vector<string> &logger);
int sortingValue(vector<string> &logger, int index);
void merge(vector<string> &logger, int low, int mid, int high);
void mergeSort(vector<string> &logger, int low, int high);
void swap(vector<string> &logger, int i, int j);
void fillFile(vector<string> &logger,int indiceInicial, int indiceFinal);
int busquedaSecuencial(vector<string> &logger, string key);

int main(void)
{

    //Declaramos variables iniciales
    string rangoin, rangofi;
    int indexin, indexfi;

    //Creamos el vector que almacena los datos del logger.
    vector<string> logger;

    // LLenamos el vector con la información del archivo de texto.
    fillVector(logger, "bitacora.txt");

    // Organizamos los datos del logger por fecha.
    mergeSort(logger, 0, logger.size() - 1);
    cout << "La lista de numeros ha sido sorteada.\n";

    cout << "Escribe la fecha de inicio para tu rango de busqueda: (Ejemplo Jun 2) ";
    getline(cin, rangoin);
    indexin = busquedaSecuencial(logger, rangoin);

    cout << "Escribe la fecha final para tu rango de busqueda: (Ejemplo Oct 9) ";
    getline(cin, rangofi);

    indexfi = busquedaSecuencial(logger, rangofi);

    fillFile(logger, indexin, indexfi);

} // cierra main

/*
Función que lee los renglones de un archivo y almacena en un vector el contenido de cada línea.

Parámetros:
referencia al vector declarado en el main.
Nombre del archivo logger leer.

*/
void fillVector(vector<string> &logger, string fileName)
{

    string s;
    ifstream in(fileName);

    while (getline(in, s))
    {
        logger.push_back(s);
    }
}


/*
Función que toma los indices con la busqueda correcta y llenan los datos en el archivo
*/
void fillFile(vector<string> &logger,int indiceInicial, int indiceFinal)
{
    ofstream myfile ("archivoFinal.txt");
    if (myfile.is_open()){
        for(int i = indiceInicial; i <= indiceFinal; i++)
        {
            myfile << logger[i] << endl;
        }
        cout << "¡Se guardaron los datos en el archivo!" << endl;
        myfile.close();
    }  
    
}

/*
Función para imprimir el vector que contiene los logs.
*/
void printVector(vector<string> &logger)
{
    // Loop de impresión
    /*for (auto i = logger.begin(); i != logger.end(); ++i)
    {
        cout << *i << "\n";
    } */

    for (int i = 10000; i < 10050; i++)
    {
        cout << logger[i] << i << "\n";
    }

    cout << "\n\n";
}

/*
Función que devuelve un valor con el cual se pueda comparar qué tan tarde se hizo un log.
Con este valor devuelto se puede llevar logger cabo un sorting.

Parámetros: 
    1. vector<string> &logger: referencia al vector que contiene los logs.
    2. int index: indice del log logger calcular su valor de sorteo.

Valores de retorno: 
    totalWeight: valor que se utilizará para sortear los vectores.
    Mientras mayor sea el valor, más tarde se hizo el log con respecto al tiempo.
*/
int sortingValue(vector<string> &logger, int index)
{

    // guardamos el string del log en una variable para modularidad.
    string log = logger[index];
    // Variable que acumula el valor de qué tan tarde se hizo un log con respecto al tiempo.
    int totalWeight = 0;

    // Creamos un diccionario para relacionar cada mes con un número.
    map<string, int> monthToNum = {
        {"Jan", 1},
        {"Feb", 200},
        {"Mar", 300},
        {"Apr", 400},
        {"May", 500},
        {"Jun", 600},
        {"Jul", 700},
        {"Aug", 800},
        {"Sep", 900},
        {"Oct", 1000},
        {"Nov", 1100},
        {"Dec", 1200}};

    // usando string indexing, cambiamos el nombre del mes logger un valor numérico.
    // usar member function map.at(*valor*) de la clase map para que nos devuelva el valor par.
    int month = monthToNum.at(log.substr(0, 3));

    // accedemos al día.
    int day = stoi(log.substr(4, 6));

    // Calculamos el peso total que tiene el tiempo en el log que se realizó.
    totalWeight = month + day;

    //cout << totalWeight;

    // Se devuelve el valor que se utilizará para sortear el vector.
    return totalWeight;
}

/*
Función que recibe strings y cambia de lugar 2 elementos de un vector o arreglo.
*/
void swap(vector<string> &logger, int i, int j)
{
    string aux;

    aux = logger[i];
    logger[i] = logger[j];
    logger[j] = aux;
}

void mergeSort(vector<string> &logger, int low, int high)
{
    int mid = (low + high) / 2;

    if (low < high)
    {
        mergeSort(logger, low, mid);
        mergeSort(logger, mid + 1, high);
        merge(logger, low, mid, high);
    }
}

void merge(vector<string> &logger, int low, int mid, int high)
{
    vector<string> aux;
    int i, j;
    i = low;
    j = mid + 1;
    // Unir los dos subarreglos en el arreglo aux.
    while (i <= mid && j <= high)
    {
        if (sortingValue(logger, i) < sortingValue(logger, j))
        {
            aux.push_back(logger[i]);
            i++;
        }
        else
        {
            aux.push_back(logger[j]);
            j++;
        }
    }

    // Insertar todos los valores restantes desde i a mid en aux.
    while (i <= mid)
    {
        aux.push_back(logger[i]);
        i++;
    }

    // Insertar todos los valores restantes desde j a high en aux.
    while (j <= high)
    {
        aux.push_back(logger[j]);
        j++;
    }

    // Asignar los valores ordenados que yacen en aux hacia el arreglo a.
    for (i = low; i <= high; i++)
    {
        logger[i] = aux[i - low];
    }
}

int busquedaSecuencial(vector<string> &logger, string key){

    for (int i = 0; i < logger.size(); i++){ //Recorremos vector

        /* Checamos si el valor a buscar tiene solo un dia "Feb 2"y checamos que el valor del indice encontrado
           tambien sea en formato de un dia "Feb 2" no "Feb 23"
        */
       //cout << key << "subtr 1: " << logger[i].substr(0,5) << "subtr2: " << logger[i][5] << "\n";
        if (key.size() == 5 && key == logger[i].substr(0,5) && logger[i][5] == ' '){
            return i;
        }
        else if(key.size() == 6 && key == logger[i].substr(0,6) ){
            return i;
        }
    }
    cout << "Es fecha no esta en el rango de datos" << endl;
}