#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// class-->cons-->funTo BuildTree.

class treeNode{
public:
    int data;
    treeNode *left;
    treeNode *right;

    //cons
    treeNode(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

// fun to buildTree
treeNode *buildTree(treeNode *root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    // create node for this
    root = new treeNode(data);

    if(data == -1) return NULL;

    // store left & right data
    cout<<"Enter data for left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right child of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

// fun for level Order traversal
void levelOrder(treeNode *root){

    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode *temp = q.front();

        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()) q.push(NULL);
        }

        else{
            cout<<temp->data<<" ";
            q.pop();

            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
    cout<<"test";
}

int main(){

    treeNode *root =NULL;

    root = buildTree(root);

    levelOrder(root);

    return 0;
}