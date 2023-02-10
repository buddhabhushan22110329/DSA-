//For sorted list
#include<iostream>
#include <bits/stdc++.h>
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

//funct to insertAtTail
void insertAtTail(node *&tail, int d){
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
//funct to print data of nodes of LL
void print(node *&head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

//funct to remove duplicates
void removeDuplicates(node *&head){
    if(head == NULL) cout<<head->data;   //ek hi node hoga tabh

    node *curr=head;
    while(curr->next!=NULL){
        if(curr->data == curr->next->data){//adj duplicate remove kro
            delete(curr->next);
            curr->next = curr->next->next;
        }

        else{//adjacent equal nhi hai toh curr ko aage badhao
            curr=curr->next;
        }
    }

    //final LL print kro
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;    

}

int main(){
    //creating first node
    node *node1 = new node(4);

    node *tail=node1;
    node *head=node1;

    insertAtTail(tail,5);
    insertAtTail(tail,6);
    insertAtTail(tail,6);
    insertAtTail(tail,8);

    cout<<"Original LL is: ";
    print(head);

    cout<<endl<<"Final LL is: ";
    removeDuplicates(head);

    return 0;
}
