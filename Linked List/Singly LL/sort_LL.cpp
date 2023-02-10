// Selection sort kind of algorithm
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node (int da){
        this->data = da;
        this->next = NULL;
    }
};

void insertAtTail(node*&tail, int d){
    node *temp=new node(d);
    tail->next=temp;
    tail=temp;
}

//funct to print data of nodes of LL
void print(node*&head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//funct to sort the data of nodes of LL
void sort(node *&head){

    node *curr = head;
    int temp;

    while(curr!=NULL){
        node *prev = curr;
        node *forward=curr->next;
        
        while(forward!=NULL){
            if(prev->data > forward->data){
                prev =forward;
            }
                forward=forward->next;
            }

            //swap data
            temp = curr->data;
            curr->data=prev->data;
            prev->data=temp;
            curr=curr->next;

        }

    //till now nodes are sorted Now print them
    
    node *b=head;
    while(b!=NULL){
        // cout<<"rf";
        cout<<b->data<<" ";
        b=b->next;
    }cout<<endl;

}

int main(){
    //create 1st node
    node *node1 = new node(3);

    node *head=node1;
    node *tail=node1;

    insertAtTail(tail,6);
    insertAtTail(tail,1);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,2);

    cout<<"LL before sorting: ";
    print(head);

    cout<<endl<<"LL after sorting: ";
    sort(head);

    return 0;
}