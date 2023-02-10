// Floyd cycle dectection algorithm is used to check if loop is present or not in LL
// it is based on slow and fast pointer(increase slow by one place & fast by two places)
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
bool floydCycleDectection(node *&head){
    if(head == NULL) return false;  //only 1 node is present in LL

    // node slow & fast will point towards head initially
    node *slow = head;
    node *fast = head;

    while(fast!= NULL && fast->next!= NULL){
        fast = fast->next->next;    //fast ko 2 times aage badhao
        slow = slow->next;          // slow ko ek place se aage badhao

        if(slow == fast){   //equal hogaye matlab loop present hai
            cout<<"Cycle is present at "<<fast->next->data<<endl;
            // will give data of node at starting of loop(This can be a seprate question with space optimization)
            // but hamesha jaruri nhi ki starting wala data hi print krega yeh...
            // iska bs itna matlab hai ki loop present hai LL me
            return true;
        }
    }
    return false;   // jab fast ya phir fast ka next NULL ho jaye tab
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

    //Creating a loop --> pointing 10 to 4
    tail->next = head->next;

    // checking is loop is present in LL or not
    if(floydCycleDectection(head)){
        cout<<"Cycle is present";
    }
    else{
        cout<<"Cycle is absent";
    }

    return 0;
}