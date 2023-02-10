//In Circular LL last wale node ka next naam ka pointer NULL ko nahi balki first wale node ka address store krta hai
// No need of head pointer bcoz, in CLL we can access 1st & last node using tail itself
//while inserting we will take user input for a node element jis ke aage hume ek nayi node daalni hai aur nayi node ka data bhi user se lengne 
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //cons
    node(int da){
        this->data = da;
        this->next = NULL;  //starting me next NULL ko point krega
    }

};

//funct to insert node      Three cases: 1)empty list 2) Only one node is there in List 3) More than one nodes
void insert(node *&tail, int currentelement, int d){

    if(tail == NULL){//matlab ki list empty hai
        //jo node add krni hai usse pehle create kro
        node *temp = new node(d);
        tail = temp;    //tail will point towards node temp
        temp->next = temp;  //circular list banane ke liye
    }
    else{   //non-empty list so, Assuming that the element is present in list
        node *curr = tail;  //curr node tail ko point karega

        //curr node will represent element wala node
        while(curr->data != currentelement){    //jab tak woh element nhi milta tab tak
            curr = curr->next;      //current node ko aage badhao
        }
        // yaha pe aagaye matlab ki element mi gaya jiske aage hume nayi node daalni hai
        // jo node add krni hai usse create kro
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
//funct to print node
void print(node* tail) {

    node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";    //tail ka data print kro
        tail = tail -> next;            // tail ko aage badhao
    } while(tail != temp);              //jab tak tail ghum phir ke wapas temp pe nahi aata tab tak 

    cout << endl;
} 


int main(){

    //node tail pointing towards NULL
    node *tail = NULL;  //starting me tail NULL ko point krega

    insert(tail,5,3);   // 5 ke aage 3 ko daal do (5 nhi hai node me phir bhi)
    print(tail);

    insert(tail,3,4);   // 3 ke aage 4 ko daaldo   
    print(tail);

    insert(tail,3,5);   // 3 ke aage matlab ki 4 ke piche 5 daal do   
    print(tail);

    return 0;
}