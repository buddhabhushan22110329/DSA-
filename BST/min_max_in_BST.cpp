// min value is present at leftMost node of tree
// max value is present at rightMost node of tree

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


// function for minValue
int minValue(BST* root){
    BST* temp = root;

    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
}


// function for maxValue
int maxValue(BST* root){
    BST* temp = root;

    while(temp->right){
        temp=temp->right;
    }
    return temp->data;
}


int main(){

    BST* root= NULL;
    cout<<"Enter data of nodes of tree: "<<endl;
    takeInput(root);

    cout<<"Min value in BST is: "<<minValue(root)<<endl;
    cout<<"Max value in BST is: "<<maxValue(root)<<endl;

    return 0;
}