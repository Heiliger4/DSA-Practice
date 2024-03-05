#include <iostream>
using namespace std;

class CircularDeque {
private:
    int* arr;
    int front, rear, size;
public:
    CircularDeque(int size) {
        arr = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }
        
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front = front - 1;
        }
        arr[front] = key;
        cout << "Inserted " << key << " at front" << endl;
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }
        
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear = rear + 1;
        }
        arr[rear] = key;
        cout << "Inserted " << key << " at rear" << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }
        
        cout << "Deleted " << arr[front] << " from front" << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }
        
        cout << "Deleted " << arr[rear] << " from rear" << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear = rear - 1;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty() || rear < 0) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    CircularDeque dq(5);
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.deleteFront();
    dq.insertFront(15);
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;
    dq.deleteRear();
    cout << "Rear element after deletion: " << dq.getRear() << endl;

    return 0;
}
