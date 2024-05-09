#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right =nullptr;
    return newNode;
}

bool isBSTUtil(Node* root, int min, int max) {

    if (root == nullptr)
        return true;
    
  
    if (root->data <= min || root->data >= max)
        return false;

    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {

    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {

    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    if (isBST(root))
        cout << "The given binary tree is a BST\n";
    else
        cout << "The given binary tree is not a BST\n";

    return 0;
}
