#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;
};

class CircularLinkedList {
private:
    CNode* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        CNode* newNode = new CNode();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteFirstNode() {
        if (head != nullptr) {
            CNode* temp = head;
            CNode* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            head = head->next;
            lastNode->next = head;
            delete temp;
        }
    }

    void deleteMiddleNode(int position) {
        if (head != nullptr) {
            CNode* temp = head;
            for (int i = 1; i < position - 1; i++) {
                temp = temp->next;
            }
            CNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }

    void deleteLastNode() {
        if (head != nullptr) {
            CNode* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            CNode* lastNode = temp->next;
            temp->next = head;
            delete lastNode;
        }
    }

    void insertAtFirst(int value) {
        CNode* newNode = new CNode();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode; 
        }
    }

    void insertAtMiddle(int value, int position){
        CNode* newNode = new CNode();
        newNode->data = value;
        CNode* temp = head;
        for (int i = 1; i < position - 1; i++) { 
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        if (head != nullptr) {
            CNode* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        } else {
            cout << "The list is empty" << endl;
        }
    }
};

int main() {
    CircularLinkedList s;

    cout << "Insert at the end: ";
    s.insertAtEnd(1);
    s.insertAtEnd(2);
    s.insertAtEnd(3);
    s.insertAtEnd(4);
    s.display();
    cout << endl;

    cout << "Delete the beginning: ";
    s.deleteFirstNode();
    s.display();

    s.insertAtFirst(1);
    cout << "Delete the Middle: ";
    s.deleteMiddleNode(2);
    s.display();

    s.insertAtMiddle(2, 2);
    cout << "Delete the End: ";
    s.deleteLastNode();
    s.display();
}
