// logic: find length of LL by traversing it
// hence index of mid element will be (length/2) + 1
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
    //jo node add krni hai use pehle create kro
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

//funct to print nodes
void print(node *&head){
    //node temp will point towwards head
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int getlength(node *&head){
    //node temp will point towards head
    node *temp = head;
    int cnt=0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main(){
    //creeate first node jiske aage hum dusre nodes ko add krenge
    node *node1 = new node(1);

    //node head & tail will point towards node1
    node *head = node1;
    node *tail = node1;

    //inserting data inside node
    insertAtTail(tail,7);
    insertAtTail(tail,5);
    insertAtTail(tail,10);

    //printing data of nodes of LL
    cout<<"Data of all nodes: ";
    print(head);

    //printing length of LL
    cout<<endl<<"Length of LL is: "<<getlength(head);
    
    cout<<endl;

    //printing mid element in LL
    int MidEleIndex = (getlength(head)/2);
    cout<<endl<<"Index of Mid element is: "<<MidEleIndex<<endl;

    


    return 0;
}