#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a node in the tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function for Depth-First Search (DFS) traversal of a tree (preorder)
void DFS(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->val << " "; // Visit the current node

    DFS(root->left); // Recursively visit left subtree
    DFS(root->right); // Recursively visit right subtree
}

int main() {
    // Constructing the example tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Depth-First Search (DFS) traversal (preorder):" << endl;
    DFS(root);

    // Freeing memory allocated to the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
