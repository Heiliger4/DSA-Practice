#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
};

class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

void insertAtPosition(int position, int value) {
    DNode* newNode = new DNode();
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    DNode* current = head;
    int currentPosition = 1;
    while (current != nullptr && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        cout << "Position out of range" << endl;
        return;
    }

    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    newNode->prev = current;
    current->next = newNode;
}


    void insertAtEnd(int value) {
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void updateAtBeginning(int value) {
        if (head == nullptr) {
            cout << "The list is empty, update at the beginning is not possible" << endl;
            return;
        }
        head->data = value;
    }

 void updateAtPosition(int position, int value) {
    if (head == nullptr) {
        cout << "The list is empty, update at any position is not possible" << endl;
        return;
    }

    DNode* current = head;
    int currentPosition = 1;

    while (current != nullptr && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        cout << "Position out of range" << endl;
        return;
    }

    current->data = value;
}

   
void updateAtEnd(int value) {
    if (head == nullptr) {
        cout << "The list is empty, update at the end is not possible" << endl;
        return;
    }

    DNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->data = value;
}


    void display() {
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList s;

    s.insertAtEnd(1);
    s.insertAtEnd(2);
    s.insertAtEnd(3);
    s.insertAtEnd(4);

    cout << "Doubly linked list: ";
    s.display();
    cout << endl;

    s.updateAtBeginning(20);
    cout << "Deleting nodes at the beginning: ";
    s.display();
    cout << endl;

    s.updateAtBeginning(1);
    s.updateAtPosition(2, 30);
    cout << "Deleting nodes at the position: ";
    s.display();
    cout << endl;

    s.updateAtPosition(2, 2);
    s.updateAtEnd(40);
    cout << "Deleting nodes at the end: ";
    s.display();

    return 0;
}
