using namespace std;

class Node{

    private:

        string origin;
        string destination;
        int index;

    public:

        Node(){
            this->origin = "none";
            this->destination = "none";
            this->index = 0;
        }

        Node(string origin, string destination){
            this->origin = origin;
            this->destination = destination;
            this->index = 0;
        }

        Node(string origin, int index){
            this->origin = origin;
            this->destination = origin; // es el primer nodo entonces su destino será su origen nhp.
            this->index = index;
        }

        Node(string origin, string destination, int index){
            this->origin = origin;
            this->destination = destination;
            this->index = index;

        }

        string getOrigin(){
            return origin;
        }

        string getDestination(){
            return destination;
        }

        int getIndex(){
            return index;
        }

        void setOrigin(string origin){
            this->origin = origin;
        }

        void setDestination(string destination){
            this->destination = destination;
        }

        void setIndex(int index){
            this->index = index;
        }

};