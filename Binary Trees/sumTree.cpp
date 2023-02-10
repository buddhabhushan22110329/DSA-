// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

#include<iostream>
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

// funct to build tree
treeNode *buildTree(treeNode *root){

    int data;
    cout<<"Enter data: ";
    cin>>data;

    // creating node for this inputed data
    root = new treeNode(data);

    if(data == -1) return NULL;

    // take input of left & right childs of each node

    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of left child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// funct to calculate sum
int sum(treeNode *root, bool &ans){

    // base case
    if(root == NULL) return 0;

    int ls = sum(root->left, ans);
    int rs = sum(root->right, ans);

    // agar leaf node hai toh
    if( root->left == NULL && root->right == NULL){
        return root->data;
    }

    if(root->data != ls+rs){
        ans = false;
    }

    int SumOfSubTree = root->data + ls + rs;
    return SumOfSubTree;

}

int main(){

    treeNode *root = NULL;
    root = buildTree(root);

    bool ans = true;
    sum(root, ans);
    
    if(ans == true) cout<<"Yes it is a sum tree "<<endl;
    if(ans == false) cout<<"No it is not a sum tree"<<endl;

    return 0;
}