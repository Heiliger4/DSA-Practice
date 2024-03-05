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

    void updateFirstNode(int value) {
        if (head != nullptr) {
            head->data = value;
        }
    }

    void updateMiddleNode(int value, int position) {
        if (head != nullptr) {
            CNode* temp = head;
            for (int i = 1; i < position; i++) {
                temp = temp->next;
            }
            temp->data = value;
        }
    }

    void updateLastNode(int value) {
        if (head != nullptr) {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->data = value;
        }
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
    cout<<endl;

    cout << "Update at the beginning: ";
    s.updateFirstNode(10);
    s.display();

    s.updateFirstNode(1);
    cout << "Update at the Middle: ";
    s.updateMiddleNode(15, 2);
    s.display();

    s.updateMiddleNode(2, 2);
    cout << "Update at the End: ";
    s.updateLastNode(20);
    s.display();
}
