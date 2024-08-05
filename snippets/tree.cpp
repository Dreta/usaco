class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};
