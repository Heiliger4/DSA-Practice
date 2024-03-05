#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define a struct to represent a node in the graph
struct Node {
  int data;
  std::vector<Node*> neighbors;

  // Constructor to initialize a node
  Node(int data) : data(data), neighbors() {}
};

// Function to perform Depth-First Traversal (DFT) of a graph
void dfsTraversal(Node* root) {
  if (root == nullptr) return;

  // Visit the current node
  std::cout << root->data << " ";

  // Visit all the neighbors of the current node
  for (Node* neighbor : root->neighbors) {
    dfsTraversal(neighbor);
  }
}

// Function to perform Breadth-First Traversal (BFT) of a graph
void bfsTraversal(Node* root) {
  if (root == nullptr) return;

  // Use a queue to store the nodes to be visited
  std::queue<Node*> queue;

  // Add root node to queue
  queue.push(root);

  // Iterate through queue and traverse graph
  while (!queue.empty()) {
    Node* current = queue.front();
    std::cout << current->data << " ";

    // Add current node's neighbors to queue
    for (Node* neighbor : current->neighbors) {
      if (neighbor != nullptr) {
        queue.push(neighbor);
      }
    }

    // Pop current node from queue
    queue.pop();
  }
}

int main() {
  // Create a graph with 5 nodes and 4 edges
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);

  // Add edges to the graph
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node3);
  node2->neighbors.push_back(node4);
  node3->neighbors.push_back(node5);

  cout<<"Perform DFS: ";
  dfsTraversal(node1);
  cout<<endl;

  cout<<"Perform BFS: ";
  bfsTraversal(node1);
  cout<<endl;

  return 0;
}

/*
  Depth-First Traversal (DFS) and Breadth-First Traversal (BFS) 
  are two popular graph traversal algorithms used to traverse a graph. 
  Here are the main differences between them:

1. Traversal Path:
	* DFS traverses the graph by exploring as far as 
    possible along each branch before backtracking.
	* BFS traverses the graph in a layer-by-layer fashion, 
    visiting all the nodes in a layer before moving on to the next layer.
2. Visit Order:
	* In DFS, the nodes are visited in a depth-first order, 
    meaning that all the nodes at a given depth are visited before 
    moving on to the next depth.
	* In BFS, the nodes are visited in a breadth-first order, 
    meaning that all the nodes in a given layer are visited before 
    moving on to the next layer.
3. Queue Requirement:
	* DFS does not require a queue to store the nodes to be visited, 
    as the traversal is depth-first.
	* BFS requires a queue to store the nodes to be visited, 
    as the traversal is breadth-first.
4. Memory Requirement:
	* DFS requires more memory than BFS because it keeps track 
    of the nodes that have been visited, as well as the nodes 
    that are yet to be visited.
	* BFS requires less memory than DFS because it only keeps 
    track of the nodes that are yet to be visited.
5. Time Complexity:
	* DFS has a time complexity of O(V+E), where V is the 
    number of vertices and E is the number of edges in the graph.
	* BFS has a time complexity of O(E+V), where V is the 
    number of vertices and E is the number of edges in the graph.

In summary, DFS traverses the graph in a depth-first manner, 
while BFS traverses the graph in a breadth-first manner. 
DFS requires more memory than BFS, but has a better time complexity 
for highly connected graphs. BFS requires less memory than DFS 
but has a worse time complexity for highly connected graphs.  
*/
