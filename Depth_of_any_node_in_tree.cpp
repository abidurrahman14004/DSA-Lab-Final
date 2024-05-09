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

int height(Node * root)
{
  if (root == NULL)
    return 0;
  
  int leftDepth = height(root->left);
  int rightDepth = height(root->right);

  if (leftDepth > rightDepth)
    return leftDepth+1;
  else
    return rightDepth+1;
}
int findDepth(Node* root, int x)
{
 
    if (root == NULL)
        return -1;
 
    int d= -1;
 
 
    if ((root->value == x) || (d = findDepth(root->left, x))>= 0 || (d = findDepth(root->right, x)) >= 0)
        return d + 1;
 
    return d;
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->left->right = new Node(7);
  root->right->right->left = new Node(8);

  cout << "The height of the tree is: " << height(root) << endl;

  cout<<"Enter the value: ";
  int x;
  cin>>x;
  cout<<"The depth of the node is "<<findDepth(root,x);

  return 0;
}
