#include <iostream>   // Include input/output library
#include <vector>     // Include vector library for using vectors
#include <queue>      // Include queue library for using queues
using namespace std;  // Use the standard namespace

struct TreeNode {    // Define a structure for a binary tree node
    int val;         // Declare an integer value for the node
    TreeNode* left;  // Declare a pointer to the left child node
    TreeNode* right; // Declare a pointer to the right child node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor to initialize the node with value x
};

void preOrder(TreeNode* root) {   // Function for pre-order traversal of the binary tree
    if (root != nullptr) {        // If the root is not null
        cout << root->val << " ";  // Output the value of the current node
        preOrder(root->left);      // Recursively call preOrder for the left subtree
        preOrder(root->right);     // Recursively call preOrder for the right subtree
    }
}

void inOrder(TreeNode* root) {    // Function for in-order traversal of the binary tree
    if (root != nullptr) {        // If the root is not null
        inOrder(root->left);      // Recursively call inOrder for the left subtree
        cout << root->val << " ";  // Output the value of the current node
        inOrder(root->right);      // Recursively call inOrder for the right subtree
    }
}

void postOrder(TreeNode* root) {  // Function for post-order traversal of the binary tree
    if (root != nullptr) {        // If the root is not null
        postOrder(root->left);     // Recursively call postOrder for left subtree
        postOrder(root->right);    // Recursively call postOrder for the right subtree
        cout << root->val << " ";  // Output the value of the current node
    }
}

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {  // Depth-first search function for graph traversal
    if (visited[node]) {      // If the node has been visited
        return;               // Exit the function
    }
    visited[node] = true;     // Mark the node as visited
    cout << node << " ";      // Output the current node
    for (int neighbor : graph[node]) {  // Iterate through the neighbors of the current node
        dfs(graph, neighbor, visited);   // Recursively call dfs for each neighbor
    }
}

void bfs(vector<vector<int>>& graph, int start) {  // Breadth-first search function for graph traversal
    vector<bool> visited(graph.size(), false);   // Keep track of visited nodes
    queue<int> q;                                // Queue for BFS traversal
    q.push(start);                               // Add the start node to the queue

    while (!q.empty()) {                          // While the queue is not empty
        int node = q.front();                     // Get the front node from the queue
        q.pop();                                  // Remove the front node from the queue

        if (!visited[node]) {                     // If the node has not been visited
            visited[node] = true;                 // Mark the node as visited
            cout << node << " ";                   // Output the current node

            for (int neighbor : graph[node]) {    // Iterate through the neighbors of the current node
                if (!visited[neighbor]) {         // If the neighbor has not been visited
                    q.push(neighbor);             // Add the neighbor to the queue
                }
            }
        }
    }
}

int main() {  // Main function
    // Binary Tree Traversal
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder Traversal: ";
    preOrder(root);  // Call the preOrder function to perform pre-order traversal
    cout << endl;

    cout << "Inorder Traversal: ";
    inOrder(root);   // Call the inOrder function to perform in-order traversal
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrder(root);  // Call the postOrder function to perform post-order traversal
    cout << endl;

    // Graph Traversal (DFS)
    int numNodes = 6;
    vector<vector<int>> graph(numNodes);
        graph[0] = {1, 2};  // Assign the neighbors of node 0
    graph[1] = {3, 4};  // Assign the neighbors of node 1
    graph[2] = {5};      // Assign the neighbors of node 2

    vector<bool> visited(numNodes, false);  // Create a vector to keep track of visited nodes
    cout << "Graph Traversal (DFS): ";
    dfs(graph, 0, visited);  // Call the dfs function to perform graph traversal using DFS
    cout << endl;

    // Graph Traversal (BFS)
    cout << "Graph Traversal (BFS): ";
    bfs(graph, 0);  // Call the bfs function to perform graph traversal using BFS
    cout << endl;

    return 0;  // Exit the program
}
