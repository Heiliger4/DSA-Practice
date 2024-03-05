#include <iostream>
#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == (MAX_SIZE - 1));
    }

    void push(int x) {
        if (isFull()) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = x;
        std::cout << x << " pushed into stack" << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return;
        }
        std::cout << arr[top--] << " popped from stack" << std::endl;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return arr[top];
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
