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

    void insertAtEnd(int value){
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        DNode* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }

    void traverseForward() {
        DNode* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void traverseBackward() {
        DNode* lastnode = head;
        while (lastnode->next != nullptr) {
            lastnode = lastnode->next;
        }
        while (lastnode != nullptr) {
            cout << lastnode->data << " ";
            lastnode = lastnode->prev;
        }
    }
};

int main(){
    DoublyLinkedList s;
    cout<<"Insertion at the end ";
    cout<<endl;
    s.insertAtEnd(1);
    s.insertAtEnd(2);
    s.insertAtEnd(3);
    s.insertAtEnd(4);
    cout << "Traversing forward: ";
    s.traverseForward();
    cout<<endl;
    cout << "Traversing backward: ";
    s.traverseBackward();
}

/*
The conditions "while (lastnode->next != nullptr)" and "while (lastnode != nullptr)" are similar in that 
they both iterate through the list until the last node is reached. 

- "while (lastnode->next != nullptr)": This condition specifically checks 
if the next node of the current node is not a nullptr. 
{still on the link}

- "while (lastnode != nullptr)": This condition checks 
if the current node itself is not a nullptr. 
{ke linku yebetesewal}

In summary, both conditions effectively iterate until the last node is reached, but 
"while (lastnode->next != nullptr)" specifically ensures that the traversal stops when the last node is reached.  
*/