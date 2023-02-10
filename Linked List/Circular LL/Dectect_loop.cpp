// check if there any loop or cycle is present in LL or not?
#include<iostream>
#include<map>
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

//funct to add node at tail
void insertAtTail(node *&tail){
    node *temp = tail;

}

int main(){
    //creating first node
    node *node1 = new node(1);

    //head & tail will point towards node1
    node *tail = node1;
    node *head = node1;



    return 0;
}
