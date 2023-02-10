#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node(int da){
        this->data = da;
        this-> next = NULL;
    }
};

//function to insert data at tail
void insertAtTail(node *&tail, int d){
    // jis node ko  add karenge use pahile create kro
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
    // tail = tail->next;
}

// function to print LL
void print(node *&head){
    node *b = head;
    
    while(b != NULL){
        cout<<b->data<<" ";
        b = b->next;
    }
    cout<<endl;
}


int main(){
    //create first node jiske tail pe hum dusre elements daalne wale hai
    node *node1 = new node(1);
   
    // pointer tail of type node will point towards node1
    node *tail = node1;
    node *head = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    print(head);


    return 0;
}