#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    // cons
    Node(int da){
        this->data=da;
        this->next=NULL;
    }
};

// funct to add a node at tail (end)
Node *insertAtTail(Node *&tail, int data){

    // jis node ko add krna hai usko create kro
    Node *temp = new Node(data);

    tail->next=temp;
    tail=temp;
}

// funct to print nodes of LL
void print(Node *head){
    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// funct to rev in k grps
Node *revInKgroups(Node *&head, int k){

    // step1: reverse first K nodes
    Node *prev=NULL;
    Node *forward=NULL;
    Node *curr =head;
    int cnt=1;

    while(curr!=NULL && cnt<=k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
    }

    // step2: aage ke node bhi reverse kro aur uske head ko iss wale ke head->next pe daal do
    if(forward!=NULL){
        head->next = revInKgroups(forward,k);
    } 

    // step3: return head of reversed LL matlab prev ko return kro
    return prev;

}

int main(){

    // create first node of LL manually
    Node *node1 = new Node(2);
    Node *tail = node1;
    Node *head = node1;

    insertAtTail(tail,3);
    // insertAtTail(tail,3);
    insertAtTail(tail,8);
    insertAtTail(tail,7);
    insertAtTail(tail,11);
    insertAtTail(tail,9);

    revInKgroups(head,2);
    print(head);

    return 0;
}