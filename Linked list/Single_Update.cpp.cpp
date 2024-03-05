#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        } cout<<endl;
    }

    void updateFirst(int value) {
        if (head != nullptr) {
            head->data = value;
        }
    }

    void updateMiddle(int position, int value) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        if (position > 0 && position < count) {
            temp = head;
            for (int i = 1; i < position; i++) {
                temp = temp->next;
            }
            temp->data = value;
        }
    }

    void updateLast(int value) {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->data = value;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    cout << "Initial Linked List: ";
    list.display();

    list.updateFirst(10);
    cout << "Linked List after updating first node: ";
    list.display();

    list.updateMiddle(2, 20);
    cout << "Linked List after updating middle node: ";
    list.display();

    list.updateLast(30);
    cout << "Linked List after updating last node: ";
    list.display();

    return 0;
}
