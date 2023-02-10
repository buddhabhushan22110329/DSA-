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
        root->right = insertNode(root->right, data);
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }

    return root;
}

void take_Input_And_Build_Tree(BST* &root){

    int data;
    cin>>data;

    while(data!=-1){
        root = insertNode(root,data);
        cin>>data;
    }
}

void levelOrder(BST* root, vector<vector<int>> &ans){
    queue<BST*>q;
    q.push(root);
    q.push(NULL);
    vector<int>v;

    while(!q.empty()){
        BST* temp = q.front();
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

    // create a root
    BST* root = NULL;
    cout<<"Enter data of nodes: "<<endl;
    take_Input_And_Build_Tree(root);

    vector<vector<int>>ans;
    levelOrder(root,ans);

    for(int i=0; i<ans.size(); i++){
        cout<<"Level "<<i<<": ";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}