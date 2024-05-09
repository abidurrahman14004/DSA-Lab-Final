#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
  
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* remove(Node* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = remove(root->left, value);
    else if (value > root->data)
        root->right = remove(root->right, value);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (value == root->data)
        return true;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 30);

    cout << "Is 20 present in the BST? " << (search(root, 20) ? "Yes" : "No") << endl;

    root = remove(root, 20);

    cout << "Is 20 present in the BST after deletion? " << (search(root, 20) ? "Yes" : "No") << endl;

    return 0;
}
