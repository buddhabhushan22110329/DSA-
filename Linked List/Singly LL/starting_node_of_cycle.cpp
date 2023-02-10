// return data of node at which loop is starting
// Algorithm: check is loop is present by FloydCycleDecetection & when slow equals to fast--> point slow towards head by keeping fast pointer as it is. Again run the while loop until slow & fast becomes equal. And this is nothing but the starting point of cycle.
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node(int da){
        this->data = da;
        this->next = NULL;
    }
};

//funct to insert at tail
void insertAtTail(node *&tail, int d){
    node *temp = new node(d);

    tail->next = temp;
    tail = temp;
}

// funct to dectect cycle or loop using floyd cycle detection algorithm
bool floydCycleDectection_AND_FindStartingNode(node *&head){
    if(head == NULL) return false;

    node *slow=head;
    node *fast=head;

    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast != NULL) fast = fast->next;
        slow = slow->next;

        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            cout<<"Starting node of cycle is: "<<slow->data<<endl;
            return true;    //starting point mil gaya
        }

    }
    cout<<"Loop is absent in LL"<<endl;
    return false;   //loop hai hi nhi LL me
}

//funct to print nodes of LL
void print(node *&head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int main(){
    //creating first node
    node *node1 = new node(6);

    //head and tail will point towards node1
    node *tail= node1;
    node *head= node1;

    insertAtTail(tail,4);
    insertAtTail(tail,22);
    insertAtTail(tail,15);
    insertAtTail(tail,10);

    //printing data of nodes of LL
    print(head);

    //Creating a loop --> pointing 10 to 22
    tail->next = head->next->next;

    floydCycleDectection_AND_FindStartingNode(head);

    return 0;
}