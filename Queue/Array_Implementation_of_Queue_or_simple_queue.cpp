#include <iostream>

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        std::cout << x << " enqueued into the queue" << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        } else if (front == rear) {
            std::cout << arr[front] << " dequeued from the queue" << std::endl;
            front = rear = -1;
        } else {
            std::cout << arr[front] << " dequeued from the queue" << std::endl;
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[front];
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
