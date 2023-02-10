// root of bTree will be given
// check if it is a complete BTree or not

// leftIndex of ele-> 2*i+1     // zero based indexing
// rightIndex of ele-> 2*i+2 
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    // cons
    Node(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }    
};

int getTotalNodes(Node* root){
    // base case
    if(root==NULL) return 0;

    int l = getTotalNodes(root->left);
    int r = getTotalNodes(root->right);

    int ans = 1+l+r;
    return ans;
}

bool isCBT(Node* root, int index, int totalNodes){
    // base case
    if(root==NULL) return true;

    if(index >= totalNodes) return false;

    else{
        bool l = isCBT(root->left, 2*index+1, totalNodes);
        bool r = isCBT(root->right, 2*index+2, totalNodes);
    }
}

int main(){

    Node* root = NULL;

    return 0;
}