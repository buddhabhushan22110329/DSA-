#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node(int da){
        this-> data= da;
        this -> next = NULL;
    }
};

//funct to insert at head
void insertAtHead(int d, node *&head){
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

//funct to insert at tail
void insertAtTail(int d, node *&tail){
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

//funct to insert node at any posi
void insertAtPosition(int position, int d, node *&head, node*&tail){

    //first position pe insert krne ke liye
    if(position == 1){
        insertAtHead(d, head);
        return;
    } 

    // agar muze kisi node ko nth position pe daalna hai toh muze pahele (n-1)th position ke node pe jana padega
    // kisi bhi position pe node ko insert krne ke liye hum uska previous wala node use krte hai
    node *temp = head;
    int count=1;
    while(count < position-1){  // (n-1)th posi tak jaane ke liye yeh while loop.
        temp = temp->next;
        count++;
    }

    // last position pe insert krne ke liye
    if(temp->next == NULL){     // matlab ki me last position pe pahuch gaya hu
        insertAtTail(d, tail);
        return;
        
    }


    //Jo node insert krna hai usse pahile create kro
    node *nodeToInser = new node(d);

    nodeToInser->next = temp->next;
    temp->next = nodeToInser;
}

//funct to print LL
void print(node *&head){
    node *b = head;

    while(b !=NULL){
        cout<<b->data<<" ";
        b = b->next;
    }
}


int main(){
    //create first node
    node *node1 = new node(1);

    // head pointing towards node1
    node *head = node1;

    // tail pointing towards node1
    node *tail = node1;

    insertAtPosition(2,100,head,tail);
    insertAtPosition(3,101,head,tail);
    insertAtPosition(1,22,head,tail);
    insertAtPosition(5, 16, head,tail);
    print(head);

    cout<<endl;

    cout<<"Head is at: "<<head->data<<endl;
    cout<<"Tail is at: "<<tail->data<<endl;

    return 0;
}