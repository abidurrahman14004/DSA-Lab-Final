#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isHeapUtil(Node* root) {

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;


    if (root->data < root->left->data || root->data < root->right->data)
        return false;


    return isHeapUtil(root->left) && isHeapUtil(root->right);
}


bool isHeap(Node* root) {
    if (root == NULL)
        return true;
    return isHeapUtil(root);
}

int main() {

    Node* root = createNode(10);
    root->left = createNode(9);
    root->right = createNode(8);
    root->left->left = createNode(7);
    root->left->right = createNode(6);
    root->right->left = createNode(5);
    root->right->right = createNode(4);

    if (isHeap(root))
        cout << "The given binary tree is a heap\n";
    else
        cout << "The given binary tree is not a heap\n";

    return 0;
}
