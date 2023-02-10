#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;

    //cons
    node(int da){
        this->data = da;
        this->prev = NULL;
        this->next = NULL;
    }
};

//funct to insert node at tail
void insertAtTail(int da, node *tail){
    node *temp = new node(da);

    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
    tail = temp;

}

//funct to print i.e transverse nodes
void print(node *&head){
    node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";  // printing data of node temp
        temp = temp->next;  //updating temp
    }cout<<endl;
}

int main(){
    //creating first node
    node *node1 = new node(3);

    //node head pointing towards node1
    node *head = node1;

    //node tail pointing towards node1
    node *tail = node1;

    print(head);

    insertAtTail(99,tail);
    insertAtTail(56,tail);
    print(head);
    return 0;
}