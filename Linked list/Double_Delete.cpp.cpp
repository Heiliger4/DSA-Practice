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

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "The list is empty, deletion at the beginning is not possible" << endl;
            return;
        }

        DNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

 void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "The list is empty, deletion at any position is not possible" << endl;
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

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}


    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "The list is empty, deletion at the end is not possible" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
        }
        delete temp;
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

    s.deleteAtBeginning();
    cout << "Deleting nodes at the beginning: ";
    s.display();
    cout << endl;

    s.insertAtBeginning(1);
    s.deleteAtPosition(2);
    cout << "Deleting nodes at the position: ";
    s.display();
    cout << endl;

    s.insertAtPosition(2,2);
    s.deleteAtEnd();
    cout << "Deleting nodes at the end: ";
    s.display();

    return 0;
}
