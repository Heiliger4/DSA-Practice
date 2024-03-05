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
        }
        cout << endl;
    }

    void deleteFirst() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtMiddle(int value, int position) {
            if (position <= 0) {
                cout << "Invalid position" << endl;
                return;
            }

        Node* temp = new Node();
        temp->data = value;

        Node* current = head;
        int count = 1;
        while (count < position - 1 && current != NULL) {
            current = current->next;  // the final current is the address
            count++;              //at the (position - 1) node
        }

        if (current == NULL) {
            cout << "Invalid position" << endl;
        } else {
            temp->next = current->next;
            current->next = temp;
        }
    }

    void deleteMiddle(int position) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        if (position > 1 && position < count) {
            temp = head;
            Node* prev = nullptr;
            for (int i = 1; i < position; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    void deleteLast() {
 if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    cout << "Initial Linked List: ";
    list.display();

    list.deleteFirst();
    cout << "Linked List after deleting first node: ";
    list.display();
    list.insertAtBeginning(1);

    list.deleteMiddle(2);
    cout << "Linked List after deleting middle node: ";
    list.display();
    list.insertAtMiddle(2, 2);

    list.deleteLast();
    cout << "Linked List after deleting last node: ";
    list.display();

    return 0;
}
