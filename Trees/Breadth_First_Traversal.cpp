#include <iostream>
#include <queue>
using namespace std;

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

// Function to perform breadth-first traversal of the binary tree
void breadthFirstTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Create a queue to hold the nodes to be traversed
    queue<Node*> q;
    q.push(root);

    // Traverse the tree level by level and print the data at each level
    while (!q.empty()) {
        Node* current = q.front();  // Get the front element of the queue (current node)
        cout << current->data << " ";  // Print the data of the current node
        if (current->left != nullptr) {  // If the current node has a left child
            q.push(current->left);  // Enqueue the left child
        }
        if (current->right != nullptr) {  // If the current node has a right child
            q.push(current->right);  // Enqueue the right child
        }
        q.pop();  // Dequeue the current node
    }
}

int main() {
    // Create a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform breadth-first traversal and print the elements
    cout << "Breadth-First Traversal: ";
    breadthFirstTraversal(root);
    cout << endl;

    return 0;
}
/*The line queue<Node*> q; declares a queue named q that can hold pointers to nodes (Node*). 
This queue is used to traverse the binary tree level by level, 
making it an integral part of the breadth-first traversal algorithm.*/