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

    void insertAtEnd(int value){
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
        while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
    } else {
        cout << "The list is empty" << endl;
    }
    head = nullptr;
}
};

int main() {
    CircularLinkedList s;
    cout<<"Insert at the beginning ";
    s.insertAtFirst(1);
    s.insertAtFirst(2);
    s.insertAtFirst(3);
    s.insertAtFirst(4);
    s.display();
    cout<<endl;

    cout<<"Insert at the end ";
    s.insertAtEnd(1);
    s.insertAtEnd(2);
    s.insertAtEnd(3);
    s.insertAtEnd(4);
    s.display();
    cout<<endl;

    cout<<"Insert at the Middle ";
    s.insertAtEnd(1);
    s.insertAtEnd(2);
    s.insertAtMiddle(15, 3); 
    s.insertAtEnd(3);
    s.insertAtEnd(4);
    s.display();
    cout<<endl;
}
