#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    //cons
    node(int da){
        this->data=da;
        this->next=NULL;
    }
};

//funct to add at tail
void insertAtTail(node* &tail, int d){
    node* temp = new node(d);
    tail->next = temp;
    tail=temp;
}

// funct to print LL
void print(node* &head1){
    node* temp=head1;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

// funct to clone LL
void clone(node* head1, node* head2){
    node* temp1 = head1;
    node* temp2 = head2;

    while(temp1!=NULL){
        temp2->next = temp1->next;
        temp1=temp1->next;
        temp2=temp2->next;
    }

    node* temp=head2;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
    
}

int main(){
    // creating first node
    node *node1 = new node(3);

    //head1 & tail will points towards node1
    node *head1=node1;
    node *tail=node1;

    insertAtTail(tail,5);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,8);

    cout<<"Original LL is: ";
    print(head1);

    // dusri node
    
    node *node2 = new node(3);
    node *head2=node2;

    cout<<"Clonned LL is:  ";
    clone(head1,head2);

    return 0;
}