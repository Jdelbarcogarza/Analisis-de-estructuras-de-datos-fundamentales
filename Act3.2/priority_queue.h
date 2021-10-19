#include <vector>


using namespace std;

/*Lista priorizada donde los elementos de mayor valor tienen prioridad*/
class priority_queue{

    public:
        priority_queue();
        void push(int dato);
        void pop();
        int top();
        bool empty();
        int size();
        void print();


    private:

        vector<int> datos;
};

priority_queue::priority_queue(){}

int parent(int i){ return (i - 1) / 2; }

/*Agregue un dato a la fila priorizada*/
void priority_queue::push(int dato){

    datos.push_back(dato); // Se hace un append a la lista de datos
    int index = datos.size() - 1;

    while(index > 0 && datos[parent(index)] < datos[index]){
        // Cambiamos los elementos de posición.
        swap(datos[index], datos[parent(index)]);
        
        index = parent(index); // la POSICIÓN del padre pasa a ser nodo hijo. Es su posicion correcta
    }
}

void maxHeapify(vector<int> &datos, int i){

    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;

    if(left <= datos.size() && datos[left] > datos[right]){
        largest = left;
    } else { 
        largest = i;
    }

    if (right <= datos.size() && datos[right] > datos[largest]){
        largest = right;
    }

    if (largest != i){
        swap(datos[i], datos[largest]);
        maxHeapify(datos, largest);
    }
}

/*Saca de la fila priorizada el dato que tiene mayor prioridad*/
void priority_queue::pop(){
    
    //cout << heapExtractMax(datos) << endl;

    if (size() < 0){
        cout << "Heap underflow" << endl;
        return;
    }

    if (empty() == true){
        cout << "La lista ya esta vacia" << endl;
        return;
    }
    
    // El más grande está siempre al inicio.
    int max = datos[0];

    // el último (menor valor) pasalo al frente para reorganizar todo el árbol y conservar propiedad.
    datos[0] = datos[datos.size() - 1];

    datos.pop_back(); // ya pasaste el más pequeño al frente. Borra el que está al final que es el mismo valor

    maxHeapify(datos, 0); // reorganizas el árbol 
}

/*Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.*/
int priority_queue::top(){

    if (datos.size() >= 1){
        return datos[0];
    } 

    cout << "No hay elementos en la lista" << endl;
    return -1;
}

/*Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.*/
bool priority_queue::empty(){

    return (datos.size() == 0) ? true : false;
}

/*Regresa la cantidad de datos que tiene la fila priorizada*/
int priority_queue::size(){

    return datos.size();
}

/*Función que imprimie la lista priorizada*/
void priority_queue::print(){

    if (empty()){
        cout << "La lista de prioridad esta vacia" << endl;
        return;
    }

    int i = 0;
    while(i < datos.size()){
        cout << datos[i] << " ";
        i++;
    }
    cout << endl;
}
