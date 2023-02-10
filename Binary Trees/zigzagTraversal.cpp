#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// class for binary tree
class treeNode{
    public:
        int data;
        treeNode* left;
        treeNode* right;

        // cons
        treeNode(int x){
            this->data=x;
            this->left=NULL;
            this->right=NULL;
        }
};

// funct to build tree
treeNode* buildTree(treeNode* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    // us data ki ek node tayar kro
    root = new treeNode(data);

    if(data==-1) return NULL;

    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);
}

// Level order traversal--> aapni wali method
void levelOrder(treeNode* root, vector<vector<int>> &ans){
    
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
            // cout<<temp->data<<" ";
            v.push_back(temp->data);
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void zigZag(treeNode* root, vector<vector<int>> &ans){
    queue<treeNode*>q;
    q.push(root);
    bool leftToRight = true;
    // q.push(NULL);


    while(!q.empty()){

        int size = q.size();
        vector<int> v(size);

        for(int i=0; i<size; i++){

            treeNode* temp = q.front();
            q.pop();

            int index;
            if(leftToRight) index=i;
            if(!leftToRight) index = size-i-1;

            v[index] = temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        // yaha aagaye matlab ki level khatam hogaya
        // direct reverse krdo
        leftToRight = !leftToRight;
        // for(auto x:v){
        //     ans.push_back(x);
        // } 
        ans.push_back(v);
    }
}

int main(){

    treeNode* root= NULL;

    root = buildTree(root);

    vector<vector<int>>ans;
    //levelOrder(root,ans);
    zigZag(root,ans);

    for(int i=0; i<ans.size(); i++){
        cout<<"Level "<<i<<": ";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}