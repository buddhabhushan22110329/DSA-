#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node(int da){
        this -> data = da;
        this -> next = NULL;
    }
};

// funct to insert at head
void insertAtHead(node *&head, int data){
    // jo node add krna hai usse pahile create kro
    node *temp = new node(data);

    temp->next = head;
    head = temp;
}

// funct to delete node by its position
void deleteNode(int position,node *&head){

    if(position == 1){  // start wala node delete krne ke liye

    }

    else{   // deleting any node other than start wala node

    node *curr = head;
    node *prev = NULL;
    int count=1; 

    while(count < position){
        prev = curr;
        curr = curr->next;
        count++;
    }
    // yaha aane ke baad me uss posi pe aagaya hu jaha se muze node ko delete krna hai
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;        // memory free krne ke liye

    }
}

int main(){
    // creating firt node
    node *node1 = new node(1);

    // head pointing towards node1
    node *head = node1;


    return 0;
}