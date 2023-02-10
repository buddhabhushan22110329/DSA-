#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    // cons
    TreeNode(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }    
};

// funct to build tree
TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    root = new TreeNode(data);
    if(data==-1) return NULL;

    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

TreeNode* solve(TreeNode* root, int n1, int n2){
    // base case
    if(root==NULL) return NULL;

    if(root->data==n1 || root->data==n2){
        return root;
    }

    TreeNode* leftNode = solve(root->left, n1,n2);
    TreeNode* rightNode = solve(root->right, n1,n2);

    // 4 conditions
    if(leftNode==NULL && rightNode==NULL) return NULL;
    if(leftNode!=NULL && rightNode!=NULL) return root;
    if(leftNode!=NULL && rightNode==NULL) return leftNode;
    if(leftNode==NULL && rightNode!=NULL) return rightNode;
}

int main(){

    TreeNode* root = NULL;

    root= buildTree(root);

    int n1 = 7; int n2=9;
    TreeNode* ans = solve(root,n1,n2);
    
    cout<<"LCA of "<<n1<<" & "<<n2<<" is: ";
    cout<<ans->data<<" "<<endl;


    return 0;
}