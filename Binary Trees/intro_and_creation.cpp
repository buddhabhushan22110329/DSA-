// What is binary tree--> it a tree having childrens <= 2
// RootNode, children, parent, sibilings, ancestor, descendant, leaf
// leaf is a node which dont have any children


// LevelOrder traversal comes under (BFS) Breadth First search technique
// InOrder, PostOrder, PreOrder traversal comes under (DFS) Depth First Search  technique


/* Types of Binary Trees:
1. Full Binary Tree--> either has 0 or 2 children

*/

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    // cons
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

// funct to build tree
node *buildTree(node *root){

    int data;
    cout<<"Enter data: ";
    cin>>data;

    // creating a node for this inputed data
    root = new node(data);

    if(data == -1) return NULL;     // will consider -1 as NULL

    // take input data for left & right childs of each node

    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

int main(){

    // creating root jo starting me NULL ko point kr rha hoga
    node *root =NULL;

    // creating a tree
    root = buildTree(root);

    return 0;
}