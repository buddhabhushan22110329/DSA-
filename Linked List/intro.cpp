// Linked list is a linear data structure & is made from collection of nodes
// we can grow or shrink elements on runtime
// node is like a capsule firstly having data and than address of next node
// types of LL-> singly, doubly, circular, circular doubly
#include<iostream>
using namespace std;

class Node{
    public:
    int data;       
    Node* next;     // this is next to data & contains address of next node(so, it is a pointer)

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

//funct for inserting node at head
void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;        // temp node ka jo next hai woh abh head ko point karega
    head = temp;                // temp node ka data abhi mera head ho gaya
}

// funct to print new LL
void print(Node* &head) {

    // temp pointed to head
    Node* temp = head;

    while(temp != NULL ) {       // jab tak temp ek dum last ko nhi jata tab tak
        cout << temp -> data << " ";    // temp node me ke data ko print kiya
        temp = temp -> next;        // temp ko aage badha diya(i.e temp abhi temp ka next hogaya)
    }
    cout << endl;
}


int main(){

    Node* node1 = new Node(10);

    //head pointed to node1
    Node* head = node1;

    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);

    return 0;
}