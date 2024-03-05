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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        std::cout << x << " pushed into stack" << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        std::cout << temp->data << " popped from stack" << std::endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Top element is: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Top element is: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Top element is: " << stack.peek() << std::endl;
    return 0;
}
