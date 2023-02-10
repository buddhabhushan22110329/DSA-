//Algorithm: create an array, copy data of nodes in array, check if array is palindrome?
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

//funct to print LL
void print(node *&head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int getLen(node *&head){
    node *temp = head;
    int cnt=0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

//copy data of nodes of LL in an array 
bool copy_Data_In_Array_And_check_if_it_is_palindrome(int arr[],int length, node *&head){
    node *temp = head;
    int i=0;
    while(temp != NULL){
        arr[i] = temp->data;
        i++;
        temp = temp->next;
    }

    //just printing copied data as array elements
    cout<<"Array elements are: ";
    for(int i=0; i<length; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    //Till this all data of nodes is copied in arr Now check if it is a palindrome
    int start=0;
    int end=length-1;

    while(start<=end){
        if(arr[start] != arr[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}


int main(){
    //create first node
    node *node1 = new node(4);

    //head & tail will point towards node1
    node *head = node1;
    node *tail = node1;

    insertAtTail(tail,2);
    insertAtTail(tail,11);
    insertAtTail(tail,2);
    insertAtTail(tail,4);

    cout<<"Data of nodes of LL is: ";
    print(head);

    int length = getLen(head);

    int arr[100];

    if(copy_Data_In_Array_And_check_if_it_is_palindrome(arr,length,head)){
        cout<<"This LL is a Palindrome"<<endl;
    } 
    else cout<<"This LL is not a Palindrome"<<endl;
    // if(!copy_Data_In_Array_And_check_if_it_is_palindrome(arr,length,head)){
    //     cout<<"This LL is not a Palindrome"<<endl;
    // }

    return 0;
}