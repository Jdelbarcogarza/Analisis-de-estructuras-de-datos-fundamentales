
class Node{

    private:

        int data;
        Node *left; // Variable que apunta a un nodo
        Node *right;

    public:

        Node(int data);
        Node(int data, Node *left, Node *right);
        int getData();
        Node* getLeft();
        Node* getRight();
        void setLeft(Node *left);
        void setRight(Node *right);

};

Node::Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int data, Node *left, Node *right){
    this->data = data;
    this->left = left;
    this->right = right;
}

int Node::getData(){
    return this->data;
}

Node* Node::getLeft(){
    return this->left;
}

Node* Node::getRight(){
    return this->right;
}

void Node::setLeft(Node* left){
    this->left = left;
}

void Node::setRight(Node* right){
    this->right = right;
}