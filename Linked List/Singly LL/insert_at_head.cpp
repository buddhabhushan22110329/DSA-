#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node(int da){
        this-> data = da;
        this-> next = NULL;
    }
};

//funct to insert element at heaad
void insertAtHead(node* &head, int d){
    // naya node banao jise hume add krna hai 
    node *temp = new node(d);

    temp->next = head;      // pahile temp ke next pe NULL tha lekin abhi woh head ko point karega
    head = temp;            // jo data hum add krne wale hai waha pe abhi head chala gaya
}

void printLL(node *&head){
    node *b = head;         // pointer b abhi head ko point karega
    while(b != NULL){
        cout<<b->data<<" ";
        b = b->next;        // b ko aage badha diya(i.e b abhi b ka next hogaya)
    }
}

int main(){
    // create pahila wala node & then uske head pe dusre elements daal denge baad me
    node *node1 = new node(1);

    // ek naya pointer of type node jo node1 ko point karega
    node *head = node1;

    insertAtHead(head, 2);
    insertAtHead(head, 3);
    printLL(head);

    return 0;
}