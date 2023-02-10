// return LL having 0,1,2 in sorted manner
// store count of zeros, ones, and two in 3 variables 
#include<iostream>
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

void count_then_sort(node *&head){
    node *temp=head;
    int countZero=0;
    int countOne=0;
    int countTwo=0;

    while(temp!=NULL){
        if(temp->data==0) countZero++;
        else if(temp->data ==1) countOne++;
        else if(temp->data==2) countTwo++;
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(countZero>0){
            temp->data=0; 
            countZero--;
        }
        else if(countOne>0){
            temp->data=1;
            countOne--;
        }
        else if(countTwo>0){
            temp->data=2;
            countTwo--;
        }
        temp=temp->next;
    }

    //Now printing the sorted array
    node *b=head;
    while(b!=NULL){
        cout<<b->data<<" ";
        b=b->next;
    }cout<<endl;

}


int main(){
    //creating first node
    node *node1 = new node(1);

    node *tail=node1;
    node *head=node1;

    insertAtTail(tail,0);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,2);

    cout<<"Original LL is: ";
    print(head);    

    cout<<endl<<"Sorted LL is: ";
    count_then_sort(head);
}