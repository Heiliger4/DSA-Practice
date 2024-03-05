#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize Node with data and null left and right pointers
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node with a given value into the binary search tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {  // If the tree is empty, create a new node as the root
        return new Node(value);
    }

    if (value < root->data) {  // If the value is less than the root, go to the left subtree
        root->left = insert(root->left, value);
    } else {  // If the value is greater or equal, go to the right subtree
        root->right = insert(root->right, value);
    }
    return root;  // Return the updated root of the subtree
}

// Function to perform in-order traversal of the binary search tree
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);  // Traverse the left subtree
        cout << root->data << " ";  // Print the current node's value
        inOrderTraversal(root->right);  // Traverse the right subtree
    }
}

// Function to perform pre-order traversal of the binary search tree
void preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // Print the current node's value
        preOrderTraversal(root->left);  // Traverse the left subtree
        preOrderTraversal(root->right);  // Traverse the right subtree
    }
}

// Function to perform post-order traversal of the binary search tree
void postOrderTraversal(Node* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);  // Traverse the left subtree
        postOrderTraversal(root->right);  // Traverse the right subtree
        cout << root->data << " ";  // Print the current node's value
    }
}

int main() {
    Node* root = nullptr;  // Create an empty binary search tree

    // Insert nodes into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Display the elements of the binary tree in sorted order (in-order traversal)
    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Display the elements of the binary tree in pre-order sequence
    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Display the elements of the binary tree in post-order sequence
    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
