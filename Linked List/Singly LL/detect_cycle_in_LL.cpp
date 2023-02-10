//to deallocating the array--> delete [] arr;
// check if there any loop or cycle is present in LL or not?
// logic--> 1.Using map(map is used to store key value pairs)-->hum har ek node ko traverse krenge aur usse true mark krenge aur agar hum ghum phir ke usi node pe aye jo ki obviously true hoga to tb return true krenege. sabhi nodes at start false marked honge
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
void insertAtTail(node *&tail, int d){
    node *temp = new node(d);

    tail->next = temp;
    tail = temp;
}

//funct to print nodes of LL
void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

bool dectect_loop(node *head){
    if(head == NULL) return false;  //matlab ki LL me sirf ek hi node present hai
    //creating a map to mark the visited nodes
    map<node*, bool>visited;

    node *temp = head;  //to traverse the LL

    while(temp != NULL){

        if(visited[temp] == true){ //agar kisi node pe hum wapas se aagaye matlab ki loop is present
            cout<<"Loop is present at "<<temp->data<<endl;  //returns starting of loop
            return true;
        }

        visited[temp] = true;   //jis node pe chale gaye use true marked kro(i.e visited)
        temp = temp->next;      // temp ko aage badhao
    }
    return false;   //jab temp NULL ko point krega matlab loop present nhi hai
}


int main(){
    //creating first node
    node *node1 = new node(5);

    //head & tail will point towards node1
    node *tail = node1;
    node *head = node1;

    //inserting data in node
    insertAtTail(tail,2);
    insertAtTail(tail,6);
    insertAtTail(tail,14);
    insertAtTail(tail,9);
    insertAtTail(tail,8);

    //print data of nodes of LL
    print(head);

    cout<<"Head is: "<<head->data<<endl; // head is 5
    cout<<"Tail is: "<<tail->data<<endl; // tail is 8

    //now we will point 8 towards 2 (i.e tail ka next = head ka next)
    tail->next = head->next;    // creating a loop in LL

    // checking if loop is present or not
    if(dectect_loop(head)){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop is absent"<<endl;
    }


    return 0;
}
