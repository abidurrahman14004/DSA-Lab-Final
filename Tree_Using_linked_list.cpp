#include <iostream>
using namespace std;

// Node structure for binary tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the binary tree
TreeNode* insert(TreeNode* root, char val) {
    // If the tree is empty, create a new node and return it
    if (root == nullptr) {
        root = new TreeNode(val);
        return root;
    }

    // If the node is not nullptr, traverse the tree to find a suitable position
    if (root->left == nullptr)
        root->left = insert(root->left, val);
    else if (root->right == nullptr)
        root->right = insert(root->right, val);

    return root;
}

// Recursive function for inorder traversal
void inorderTraversal(TreeNode* node) {
    if (node == nullptr)
        return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Function to perform inorder traversal
void inorder(TreeNode* root) {
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
}

// Recursive function for preorder traversal
void preorderTraversal(TreeNode* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Function to perform preorder traversal
void preorder(TreeNode* root) {
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
}

// Recursive function for postorder traversal
void postorderTraversal(TreeNode* node) {
    if (node == nullptr)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

// Function to perform postorder traversal
void postorder(TreeNode* root) {
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
}

int main() {
    TreeNode* root = nullptr;

    // Insert values into the binary tree
    root = insert(root, 'A');
    root = insert(root, 'B');
    root = insert(root, 'C');
    root = insert(root, 'D');
    root = insert(root, 'E');

    // Display the binary tree and its traversals
    inorder(root);
    preorder(root);
    postorder(root);

    return 0;
}
