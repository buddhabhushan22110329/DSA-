// Singly LL has data & next. Same as like that Doubbly LL has previous, data & next
// next is a pointer which stores data of
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;

    node(int da){
        this ->data = da;
        this ->next = NULL;
        this ->prev = NULL;
    }
};

// Traversing a LL
void print(node *&head){
    // create a temp node pointing towards head
    node *temp = head;

    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;      // updating temp
    }cout<<endl;
}

//funct to get length of LL
int getlen(node *&head){
    node *temp = head;
    int cnt=0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

//funct to insert a node at head
void insertAtHead(node *&head, int d){
    node *temp = new node(d);

    temp->next = head;
    head->prev = temp;
    head = temp;
     
}

int main(){
    //creating first node
    node *node1 = new node(10);

    // head pointing towards node1
    node *head = node1;

    print(head);

    cout<<"Length is: "<<getlen(head)<<endl;

    insertAtHead(head, 11);
    print(head);

    cout<<"new length is: "<<getlen(head)<<endl;

    return 0;
}