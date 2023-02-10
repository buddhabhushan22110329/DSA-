// return a LL which is sum of two given LL
/*
step 1: reverse both LL
step 2: add two LL  (carry,sum,digit, insert digit @tail) and store that LL in another LL ans
step 3: reverse ans LL (becoz it was reversed by defaut)
step 4: return ans LL
*/

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    //cons;
    node(int da){
        this->data = da;
        this->next= NULL;
    }
};

void insertAtTail(node *&tail, int value){
    node *temp=new node(value);
    tail->next=temp;
    tail=temp;
}

void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

//funct to reverse LL
node *reverse(node *head){
    node *curr=head;
    node *prev=NULL;
    node *forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}


//funct to add two LL
node *add(node *node1, node *node2){

}

int main(){
    node *node1 = new node(4);

    node *head1=node1;
    node *tail1=node1;

    insertAtTail(tail1,6);
    insertAtTail(tail1,8);
    insertAtTail(tail1,7);
    cout<<"First LL: ";
    print(head1);

    node *node2;    // 4 rahil data by default

    node *head2=node1;
    node *tail2=node1;

    insertAtTail(tail2,5);
    insertAtTail(tail2,9);
    insertAtTail(tail2,6);
    insertAtTail(tail2,7);
    insertAtTail(tail2,2);
    cout<<"Second LL: ";
    print(head2);
    cout<<endl;

    //step 1: reverse both LL
    node1 = reverse(node1);
    node2 = reverse(node2);

    print(node1);

    return 0;
}