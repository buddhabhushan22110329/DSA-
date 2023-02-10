#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node(int da){
        this->data = da;
        this->next = NULL;
    }
};
//funct to insert at tail
void inserAtTail(node *&tail, int d){
    //jo node add krni hai usse pehle create kro
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

//funct to reverse the LL
void reverse(node *head){

    if(head ==NULL || head->next == NULL){//list empty or sirf ek node present hai toh
        cout<<head->data<<endl;    //node vaise ka vaisa return krdo 
    }
    node *prev =NULL;
    node *forward =NULL;
    node *curr = head;

    while(curr != NULL){  // dry run this on NoteBook for better understanding
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        // cout<<prev->data<<" ";
    }

    node *temp = prev;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

//funct to print data of nodes
void print(node *&head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int main(){
    //create first node
    node *node1 = new node(1);

    //tail & head will point towards node1
    node *tail = node1;
    node *head = node1;

    //insert data
    inserAtTail(tail,2);
    inserAtTail(tail,3);
    inserAtTail(tail,4);

    //printing data of nodes
    cout<<"Before reversing: ";
    print(head);

    //Now we will reverse the nodes (i.e 1 2 3 4  to  4 3 2 1)
    //Now we will print the nodes
    cout<<endl<<"After reversing: ";
    reverse(head);

    return 0;
}