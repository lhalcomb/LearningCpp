#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class SinglyLinkedList{
    private:
        node* head; //head of the list pointed to a reference in memory from the constructor 'node'
    public: 
        SinglyLinkedList(){
            head = nullptr;
        }

        
        
}