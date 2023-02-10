#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // cons
    TreeNode(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode *buildTree(TreeNode *root){

    int data;
    cout<<"Enter data: ";
    cin>>data;

    // make a node for this data
    root = new TreeNode (data);

    if(data == -1) return NULL;

    // left & right
    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root; 
}

// InOrder traversal--> LNR
void inorder(TreeNode* root){
    
    // base case
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// PreOrder traversal--> NLR
void preorder(TreeNode *root){

    // base case
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// PostOder traversal--> LRN
void postorder(TreeNode *root){

    // base case
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// LevelOrder traversal
void levelorder(TreeNode* root){
    
    queue<TreeNode*>q;

    q.push(root);

    while(!q.empty()){
        TreeNode *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(){

    TreeNode *root=NULL;
    root = buildTree(root);

    cout<<"InOrder traversal: ";
    inorder(root); cout<<endl;

    cout<<"PreOrder traversal: ";
    preorder(root); cout<<endl;

    cout<<"PostOrder traversal: ";
    postorder(root); cout<<endl;

    cout<<"LevelOrder traversal is: ";
    levelorder(root); cout<<endl;

    return 0;
}