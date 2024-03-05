#include <iostream>
using namespace std;

// Define a struct to represent a node in the tree
struct Node {
  int data;
  Node* left;
  Node* right;

  // Constructor to initialize a node
  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal of a binary tree
void inOrderTraversal(Node* root) {
  if (root != nullptr) {
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
  }
}

// Function to perform preorder traversal of a binary tree
void preOrderTraversal(Node* root) {
  if (root != nullptr) {
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

// Function to perform postorder traversal of a binary tree
void postOrderTraversal(Node* root) {
  if (root != nullptr) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
  }
}

int main() {
  // Create a binary tree
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  // Perform inorder traversal
    cout<<"Inorder: ";
inOrderTraversal(root);
cout<<endl;

  // Perform preorder traversal
    cout<<"Pre order: ";
preOrderTraversal(root);
cout<<endl;


  // Perform postorder traversal
    cout<<"Post order: ";
postOrderTraversal(root);
cout<<endl;

  return 0;
}
