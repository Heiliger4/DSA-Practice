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

    void insertAtFirst(int value) {
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int value){
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
    }
        DNode* lastnode = head;
        while (lastnode->next != nullptr) {
            lastnode = lastnode->next;
    }
        lastnode->next = newNode;
        newNode->prev = lastnode;
    }

    void insertAtMiddle(int data, int position){
        if (position < 1) {
            cout << "Invalid position for insertion" << endl;
            return;
        }

        DNode* newNode = new DNode();
        newNode->data = data;

        DNode* current = head;
        int count = 1;

        while (count < position - 1 && current != nullptr) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Invalid position for insertion" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
}

    void display() {
        DNode* temp = head;
        head = nullptr;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
DoublyLinkedList s;
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
s.insertAtEnd(3);
s.insertAtEnd(4);
s.insertAtMiddle(15, 3);
s.display();
cout<<endl;
}
