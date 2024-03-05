#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << x << " enqueued into the queue" << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        std::cout << temp->data << " dequeued from the queue" << std::endl;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    std::cout << "Front element is: " << queue.peek() << std::endl;
    queue.dequeue();
    std::cout << "Front element is: " << queue.peek() << std::endl;
    queue.dequeue();
    std::cout << "Front element is: " << queue.peek() << std::endl;
    return 0;
}
