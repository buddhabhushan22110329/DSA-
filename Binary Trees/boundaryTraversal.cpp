/*
Algo:   1. print root ka data first
        2. print all left nodes of root except leaf nodes
        3. print all right nodes of root except leaf nodes
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    treeNode *left;
    treeNode *right;

    // cons
    treeNode(int x){
        this->data = x;
        this->left=NULL;
        this->right=NULL;
    }
};

// fun to build tree
treeNode* buildTree(treeNode* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    root = new treeNode(data);

    if(data==-1) return NULL;

    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void boundary(treeNode* root, vector<int>&ans){
    
   
}

int main(){

    treeNode* root = NULL;

    root = buildTree(root);
    vector<int> ans;
    boundary(root, ans);

    for(auto x: ans){
        cout<<x<<" ";
    }

    return 0;
}