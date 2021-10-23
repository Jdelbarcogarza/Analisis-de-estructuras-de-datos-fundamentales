using namespace std;
class Node{

    private:

        string data; //10.234.3
        Node *left; // Variable que apunta a un nodo
        Node *right;
        int numAccesos; //

    public:

        Node(string data, int numAccesos);
        Node(string data, Node *left, Node *right, int numAccesos);
        string getData();
        Node* getLeft();
        Node* getRight();
        int getNumAccesos();
        void setLeft(Node *left);
        void setRight(Node *right);
        void setNumAccesos(int numAccesos);
        void setData(string data);

};

Node::Node(string data, int numAccesos){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->numAccesos = numAccesos;
}

Node::Node(string data, Node *left, Node *right, int numAccesos){
    this->data = data;
    this->left = left;
    this->right = right;
    this->numAccesos = numAccesos;
}

string Node::getData(){
  return this->data;
}

Node* Node::getLeft(){
  return this->left;
}

Node* Node::getRight(){
  return this->right;
}

int Node::getNumAccesos(){
  return this->numAccesos;
}

void Node::setData(string data){
  this->data = data;
}

void Node::setLeft(Node* left){
    this->left = left;
}

void Node::setRight(Node* right){
    this->right = right;
}

void Node::setNumAccesos(int numAccesos){
  this->numAccesos = numAccesos;
}
