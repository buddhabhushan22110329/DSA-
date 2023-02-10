#include<iostream>
using namespace std;

class node{
    public: 
    int data;
    node *prev;
    node *next;

    //cons 
    node(int da){
        this ->data = da;
        this->next = NULL;
        this->prev = NULL;
    }
};

//funct to get length of LL
int getlen(node *&head){
    node *temp = head;
    int cnt =0;
    while(temp !=NULL){
        cnt++;
        temp= temp->next;
    }
    return cnt;
}

//funct to insert at head
void insertAtHead(node *&head, int d){
    node *temp = new node(d);

    temp->next = head;
    head->prev = temp;
    head = temp;
}

//funct to insert at tail
void insertAtTail(node *&tail, int d){
    node *temp = new node(d);

    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
    tail = temp;
}

//function to insert at any position
void insertAtPos(node *&head, node *&tail, int posi, int d){
    if(posi == 1) {
        insertAtHead(head, d);
    }

    if(posi == getlen(head)) {
        insertAtTail(tail,d);
    }

}


//funct to print OR traverse
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

    //node head pointing towards node1
    node *head=  node1;

    //node tail pointing towards node1
    node *tail = node1;

    return 0;
}