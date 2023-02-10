// /********************************************************************

    // Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
// ********************************************************************/

//funct to find mid node
node* midFun(node* head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//funct to merge 2 sorted LL
node* merge(node* left, node* right){
    
    //if left LL is empty--> return right LL
    if(left==NULL) return right;
    
    //if right LL is empty--> return left LL
    if(right==NULL) return left;    
    
    node* res=new node(-1);
    node* temp=res;
    
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
         else//(left->data > right->data)
         {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    
    while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;      
    }
    
    while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;      
    }        
    res= res->next;
    return res;
}


node* mergeSort(node *head) {
    
    //if LL has NULL or only one node
    if(head==NULL || head->next==NULL) return head;
    
    //node* originalNode = head;
    //finding mid node
    node* midNode = midFun(head);
    
    // creating 2 LL left & right
    node* left = head;
    node* right = midNode->next;
    midNode->next=NULL;
    
    //sorting left & right LL recursively
    left = mergeSort(left);
    right = mergeSort(right);
    
    // merging left & right LL (using logic of merge two sorted LL)
    node* ans = merge(left,right);
    return ans;
}
