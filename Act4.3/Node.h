template<class T>
class Node{

    private:

        T origin;
        T destination;
        T weight;

    public:

        Node(){
            this->origin = 0;
            this->destination = 0;
            this->weight = 0;
        }

        Node(T origin, T destination, T weight){
            this->origin = origin;
            this->destination = destination;
            this->weight = weight;

        }

        T getOrigin(){
            return origin;
        }

        T getDestination(){
            return destination;
        }

        T getWeight(){
            return weight;
        }

        // podemos agregar los setters pero por el momento creo que no son necesarios.

};