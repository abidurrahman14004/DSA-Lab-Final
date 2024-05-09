#include <iostream>
#include <vector>

using namespace std;

// Function to construct a complete binary tree from an array
void constructTree(vector<int> &arr, int rootIndex) {
    if (rootIndex < arr.size()) {
        int leftChildIndex = 2 * rootIndex + 1;
        int rightChildIndex = 2 * rootIndex + 2;

        // Create left subtree
        if (leftChildIndex < arr.size())
            constructTree(arr, leftChildIndex);

        // Print current node
        cout << arr[rootIndex] << " ";

        // Create right subtree
        if (rightChildIndex < arr.size())
            constructTree(arr, rightChildIndex);
    }
}

// Function for inorder traversal of the binary tree
void inorderTraversal(vector<int> &arr, int rootIndex) {
    if (rootIndex < arr.size()) {
        int leftChildIndex = 2 * rootIndex + 1;
        int rightChildIndex = 2 * rootIndex + 2;

        // Traverse left subtree
        if (leftChildIndex < arr.size())
            inorderTraversal(arr, leftChildIndex);

        // Print current node
        cout << arr[rootIndex] << " ";

        // Traverse right subtree
        if (rightChildIndex < arr.size())
            inorderTraversal(arr, rightChildIndex);
    }
}

// Function for preorder traversal of the binary tree
void preorderTraversal(vector<int> &arr, int rootIndex) {
    if (rootIndex < arr.size()) {
        int leftChildIndex = 2 * rootIndex + 1;
        int rightChildIndex = 2 * rootIndex + 2;

        // Print current node
        cout << arr[rootIndex] << " ";

        // Traverse left subtree
        if (leftChildIndex < arr.size())
            preorderTraversal(arr, leftChildIndex);

        // Traverse right subtree
        if (rightChildIndex < arr.size())
            preorderTraversal(arr, rightChildIndex);
    }
}

// Function for postorder traversal of the binary tree
void postorderTraversal(vector<int> &arr, int rootIndex) {
    if (rootIndex < arr.size()) {
        int leftChildIndex = 2 * rootIndex + 1;
        int rightChildIndex = 2 * rootIndex + 2;

        // Traverse left subtree
        if (leftChildIndex < arr.size())
            postorderTraversal(arr, leftChildIndex);

        // Traverse right subtree
        if (rightChildIndex < arr.size())
            postorderTraversal(arr, rightChildIndex);

        // Print current node
        cout << arr[rootIndex] << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; // Example array representing a complete binary tree

    cout << "Constructed tree:" << endl;
    constructTree(arr, 0); // Start construction from root
    cout << endl;

    cout << "Inorder traversal:" << endl;
    inorderTraversal(arr, 0); // Inorder traversal
    cout << endl;

    cout << "Preorder traversal:" << endl;
    preorderTraversal(arr, 0); // Preorder traversal
    cout << endl;

    cout << "Postorder traversal:" << endl;
    postorderTraversal(arr, 0); // Postorder traversal
    cout << endl;

    return 0;
}
