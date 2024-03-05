#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return (front == nullptr);
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        std::cout << x << " inserted at the front of the deque" << std::endl;
    }

    void insertRear(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        std::cout << x << " inserted at the rear of the deque" << std::endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }
        std::cout << temp->data << " deleted from the front of the deque" << std::endl;
        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }
        std::cout << temp->data << " deleted from the rear of the deque" << std::endl;
        delete temp;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }
        return rear->data;
    }
};

int main() {
    Deque deque;
    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.deleteFront();
    deque.deleteRear();
    std::cout << "Front element: " << deque.getFront() << std::endl;
    std::cout << "Rear element: " << deque.getRear() << std::endl;

    return 0;
}
