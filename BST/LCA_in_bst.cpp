 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

class bst{
    public:
    int data;
    bst* left;
    bst* right;

    // cons
    bst(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

bst* insert(bst* &root, int data){
    // base case
    if(root==NULL){
        root = new bst(data);
        return root;
    }

    if(root->data < data){
        root->right = insert(root->right, data);
    }

    else{
        root->left = insert(root->left,data);
    }
    return root;
}

void takeInput(bst* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insert(root,data);
        cin>>data;
    }
}

void solve(bst* root, int n1, int n2, int &ans){
    // base case
    if(root==NULL) return;

    if(root->data > n1 && root->data > n2){
        solve(root->left, n1,n2,ans);
    }

    else if(root->data < n1 && root->data < n2){
        solve(root->right, n1,n2,ans);
    }

    else{
        ans = root->data;
    }
}

int main(){

    bst* root = NULL;
    cout<<"Enter data of nodes: ";
    takeInput(root);

    int n1,n2;
    cin>>n1>>n2;

    int ans=-1;
    solve(root,n1,n2,ans);

    if(ans==-1){
        cout<<"NULL"<<endl;
    }
    else{
        bst* final = new bst(ans);
        cout<<"LCA of n1 & n2 is: "<<final->data<<endl;
    }

    return 0;
}