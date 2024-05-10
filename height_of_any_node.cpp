#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *left, *right;

    Node(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int findDepth(Node *root, int x)
{

    if (root == NULL)
        return -1;

    int d = -1;

    if ((root->value == x) || (d = findDepth(root->left, x)) >= 0 || (d = findDepth(root->right, x)) >= 0)
        return d + 1;

    return d;
}

int heightOfNode(Node *root, int x)
{
    if (root == NULL)
        return -1;

    if (root->value == x)
        return height(root) - 1; 

    int leftHeight = heightOfNode(root->left, x);
    if (leftHeight >= 0)
        return leftHeight;

    int rightHeight = heightOfNode(root->right, x);
    return rightHeight;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(8);

    cout << "The height of the tree is: " << height(root) << endl;

    int x;
    cout << "Enter the value of the node: ";
    cin >> x;
    int height_of_node = heightOfNode(root, x);
    if (height_of_node >= 0)
        cout << "The height of the node is: " << height_of_node << endl;
    else
        cout << "Node not found in the tree." << endl;

    return 0;
}
