// return true if target node value present in BST otherwise return false

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BST{
    public:
        int data;
        BST* left;
        BST* right;

    // cons
    BST(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

BST* insertNode(BST* &root, int data){
    // base case
    if(root==NULL){
        root = new BST(data);
        return root;
    }

    if(data > root->data){
        root->right = insertNode(root->right,data);
    }

    else{   //if(data < root->data
        root->left = insertNode(root->left, data);
    }

    return root;
}

void takeInput(BST* &root){
    int data;
    cin>>data;

    while (data != -1)
    {
        root = insertNode(root, data);
        cin>>data;
    }
    
}


// BY RECURSION-->
void solveByRecursion(BST* root, bool &isPresent, int target){
    // base case
    if(root==NULL) return;

    if(root->data == target) isPresent = true;

    if(target > root->data) solveByRecursion(root->right, isPresent, target);
    if(target < root->data) solveByRecursion(root->left, isPresent, target);
}


// Iterative method-->
bool solveByIteration(BST* root, int target){
    BST* temp = root;

    while(temp!=NULL){
        if(target == temp->data){
            return true;
        }

        if(target > temp->data){
            temp = temp->right;
        }

        if(target < temp->data){
            temp = temp->left;
        }
    }
    return false;
}

int main(){

    BST* root=NULL;
    cout<<"Enter tree nodes: "<<endl;
    takeInput(root);

    bool isPresent=false;
    int target = 187;
    // solveByRecursion(root,isPresent,target);
    if(isPresent) cout<<target<<" is present"<<endl;
    if(!isPresent) cout<<target<<" is absent"<<endl;


    bool ans = solveByIteration(root,target);
    if(ans) cout<<target<<" is present"<<endl;
    if(!ans) cout<<target<<" is absent"<<endl;

    return 0;
}