// return the middle element of LL
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

//funct to get middle element in LL
void getmiddle(node *&head){
    if(head ==NULL || head->next == NULL){//if LL contains 0 or one node
        cout<<head->next<<endl;
    }
    //node slow will point towards head
    //node fast will point towards next of head
    node *slow = head;
    node *fast = head->next;
    while(fast != NULL){

        //will increment fast by two places & slow by one place

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }//data of node slow is nothing but the mid element 
    cout<<slow->data<<endl;
}


//funct to print nodes in LL
void print(node *&head){
    node *temp = head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int main(){
    //create first node jiske aage hume dusre nodes ko dalna hai
    node *node1 = new node(5);

    //head & tail will point towards node1
    node *tail = node1;
    node *head = node1;

/*
Array
Binary Search
Sorting Algo--> sel, bubble, insertion
Strings
2D Array
Recursion
Linked List
Stacks
Queues

Binary Trees
Binary Search Tree
Heaps
Trie
Backtracking
Graphs
Dynamic Programming


*/


    //inserting data in nodes of LL
    insertAtTail(tail,6);
    insertAtTail(tail,7);
    insertAtTail(tail,8);

    //printing data of nodes of LL
    cout<<"Data of nodes of LL is: ";
    print(head);

    cout<<endl<<"Mid element is: ";
    getmiddle(head);

    return 0;
}