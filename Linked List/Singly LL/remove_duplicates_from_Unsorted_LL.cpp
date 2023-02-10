//For Unsorted list
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

void solve(node *head){
    node *curr = head;
    node *temp = curr;
    while(curr){
        
        while(temp->next){
            if(curr->data == temp->next->data){
                temp = temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;
    }

    node *t = head;
    while(t){
        cout<<t->data<<" ";
        t=t->next;
    }

}

int main(){
    //creating first node
    node *node1 = new node(3);

    node *tail=node1;
    node *head=node1;

    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,2);
    insertAtTail(tail,3);


    cout<<"Original LL is: ";
    print(head);

    cout<<endl<<"Final LL is: ";
    // removeDuplicates(head);
    solve(head);

    return 0;
}