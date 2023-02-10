// predecessor: max-element in left SubTree
// successor: min-element in right SubTree

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class bst{
public:
    int data;
    bst* left;
    bst* right;

    //cons
    bst(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

bst* insert(bst* &root, int data){
    //base case
    if(root==NULL){
        root = new bst(data);
        return root;
    }

    if(data > root->data){
        root->right = insert(root->right,data);
    }

    else{
        root->left = insert(root->left,data);
    }
    return root;
}

void takeInput(bst* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insert(root,data);
        cin>>data;
    }
}

int main(){

    bst* root = NULL;
    cout<<"Enter data of nodes: "<<endl;
    takeInput(root);

    // find pre & succ of key
    int key;
    cout<<"Enter key: ";
    cin>>key;

    // firstly get the key node
    bst* temp = root;
    while (temp->data != key)
    {
        if(key > temp->data){
            temp = temp->right;
        }

        else{
            temp = temp->left;
        }
    }

    bst* keyNode = temp;

    // max element in left SubTree of keyNode is predecessor
    // min element in right SubTree of keyNode is successor

    // pred
    bst* leftTree = keyNode->left;  // now find max of leftTree
    int pred;

    while(leftTree!=NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ
    bst* rightTree = temp->right;   // now find min of rightTree
    int succ;

    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int,int>p;
    p.first = pred;
    p.second = succ;

    cout<<"Predecessor: "<<pred<<endl;
    cout<<"Successor: "<<succ<<endl;

    return 0;
}