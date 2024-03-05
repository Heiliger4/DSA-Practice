# include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* go;
};

class single{
private: 
    Node* head;
public:
    single(){
        head = nullptr;
    }

    void insertAtFirst(int data){
        Node* temp = new Node();
        temp -> value = data;
        temp -> go = head;  
        head = temp;
    }

    void insertAtEnd(int data){
        Node* temp = new Node();
        temp->value = data;
        temp->go = NULL;  
        
            if (head == NULL) {
                head = temp;  
            } else {
                Node* current = head;
                while (current->go != NULL) {
                    current = current->go;  
                }
                current->go = temp;  
            }
    }

    void insertAtMiddle(int data, int position) {
            if (position <= 0) {
                cout << "Invalid position" << endl;
                return;
            }

        Node* temp = new Node();
        temp->value = data;

        Node* current = head;
        int count = 1;
        while (count < position - 1 && current != NULL) {
            current = current->go;  // the final current is the address
            count++;              //at the (position - 1) node
        }

        if (current == NULL) {
            cout << "Invalid position" << endl;
        } else {
            temp->go = current->go;
            current->go = temp;
        }
    }

    void display(){
        Node* tmp = head;
        head = nullptr;
        while(tmp!=nullptr){
            cout <<tmp->value<<" ";
            tmp = tmp->go;
        }
    }
};

int main() {
single s;
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