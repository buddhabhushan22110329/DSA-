#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    treeNode *left;
    treeNode *right;

    //cons
    treeNode(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

// funct to create tree
treeNode *buildTree(treeNode *root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    // creating a node for this data
    root = new treeNode(data);

    if(data == -1) return NULL;

    // take input data for left & right childs of each node
    
    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

void levelOrder(treeNode *root, vector<vector<int>>&ans){

    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);
    vector<int> v;

    while(!q.empty()){
        treeNode* temp = q.front();

        if(temp==NULL){
            ans.push_back(v);
            v.clear();
            q.pop();

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            v.push_back(temp->data);
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

}

int main(){

    treeNode *root = NULL;

    root = buildTree(root);
    vector<vector<int>>ans;
    levelOrder(root,ans);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}