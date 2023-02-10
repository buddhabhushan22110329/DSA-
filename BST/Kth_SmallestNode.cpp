// brute force: Use inOrder traversal to store elements in vector & return (k-1)th element
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

BST* insertNode(BST* root, int data){
    // base case
    if(root==NULL){
        root = new BST(data);
        return root;
    }

    if(data > root->data){
        root->right = insertNode(root->right,data);
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    return root;
}

void takeInput(BST* root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertNode(root, data);
        cin>>data;
    }
}

int main(){

    BST* root=NULL;

    cout<<"Enter data of nodes: "<<endl;
    takeInput(root);

    return 0;
}