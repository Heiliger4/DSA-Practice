#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {  // Constructor to initialize Node with data and null left and right pointers
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {  // If the tree is empty, create a new node as the root
        return new Node(value);
    }

    if (value < root->data) {  // If the value is less than the root, go to the left subtree
        root->left = insert(root->left, value);
    } else {  // If the value is greater or equal, go to the right subtree
        root->right = insert(root->right, value);
    }
    return root;  // Return the updated root
}

Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value) {  // If the node is null or the value is found at the current node
        return root;
    }

    if (value < root->data) {  // If the value is less than the current node's value, search in the left subtree
        return search(root->left, value);
    } else {  // If the value is greater, search in the right subtree
        return search(root->right, value);
    }
}

Node* findMin(Node* node) {  // Helper function to find the node with the minimum value in the subtree
    while (node->left != nullptr) {
        node = node->left;  // Keep moving left until the leftmost node is found
    }
    return node;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {  // If the tree is empty
        return root;
    }

    if (value < root->data) {  // If the value is less than the current node's value, go to the left subtree
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {  // If the value is greater, go to the right subtree
        root->right = deleteNode(root->right, value);
    } else {  // If the value is found at the current node
        if (root->left == nullptr) {  // If the node has no left child
            Node* temp = root->right;  // Replace the node with its right child
            delete root;
            return temp;  // Return the right child as the new root of the subtree
        } else if (root->right == nullptr) {  // If the node has no right child
            Node* temp = root->left;  // Replace the node with its left child
            delete root;
            return temp;  // Return the left child as the new root of the subtree
        }
        Node* temp = findMin(root->right);  // If the node has both left and right children, find the minimum value in the right subtree
        root->data = temp->data;  // Replace the node's value with the minimum value from the right subtree
        root->right = deleteNode(root->right, temp->data);  // Delete the node with the minimum value from the right subtree
    }
    return root;  // Return the updated root
}

void inOrderTraversal(Node* root) {  // Function to perform in-order traversal of the binary search tree
    if (root != nullptr) {
        inOrderTraversal(root->left);  // Traverse the left subtree
        cout << root->data << " ";  // Print the current node's value
        inOrderTraversal(root->right);  // Traverse the right subtree
    }
}

int main() {
    Node* root = nullptr;  // Create an empty binary search tree

    root = insert(root, 50);  // Insert nodes into the binary search tree
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Binary Search Tree (InOrder Traversal): ";
    inOrderTraversal(root);  // Display the elements of the binary search tree in sorted order
    cout << endl;

    int searchValue = 60;
    Node* searchResult = search(root, searchValue);  // Search for a specific value in the tree
    if (searchResult != nullptr) {
        cout << searchValue << " found in the tree." << endl;
    } else {
        cout << searchValue << " not found in the tree." << endl;
     
    }

    // Deleting a node with value 20
    root = deleteNode(root, 20);

    cout << "Binary Search Tree (InOrder Traversal): ";
    inOrderTraversal(root);  // Display the elements of the binary tree in sorted order after deletion
    cout << endl;

    return 0;
}
