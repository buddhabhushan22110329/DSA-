// array of inOrder & preOrder traversal will be given, construct bTree from it & return root of binary tree
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// class for tree
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

// creating a funct to build tree
TreeNode* buildTree(TreeNode* root){

    int data;
    cout<<"Enter data: ";
    cin>>data;

    root = new TreeNode(data);
    if(data==-1) return NULL;

    // go to left & right
    cout<<"Enter data for left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrder(TreeNode* root, vector<int>v, vector<vector<int>>&ans){
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp==NULL){
            ans.push_back(v);
            v.clear();

            if(!q.empty()) q.push(NULL);
        }
        else{
            v.push_back(temp->data);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main(){

    TreeNode* root = NULL;
    root = buildTree(root);

    vector<int>v;
    vector<vector<int>>ans;

    levelOrder(root,v,ans);

    cout<<endl<<"Given tree is: "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<"Level "<<i<<": ";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }


    return 0;
}