#include <iostream>

using namespace std;

/* struct node{
    int data;
    node *next;
}; */

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            this->data = val;
            this->next= nullptr;
        }
};

class SinglyLinkedList{
    private:
        Node* head; //head of the list pointed to a reference in memory from the constructor 'node'
    public: 
        SinglyLinkedList()
        {
            head = nullptr;
        }

        void insertNodeAtBeginning(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        void insertNodeAtEnd(int val){
            Node* newNode = new Node(val);
            if (head == nullptr){
                head = newNode;
            }else{
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;

                }
                temp->next = newNode;
            }
            
        }

        void printList(){
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
        
};

int main(){
    SinglyLinkedList sll;
    /*sll.insertNodeAtEnd(1);
    sll.insertNodeAtEnd(2);*/
    int n = 50;
    for (int i = 0; i < n; i++){
        if (i%2==0){
            sll.insertNodeAtEnd(i);
        }
    }

    sll.printList();
}