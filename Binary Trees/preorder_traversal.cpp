// preorder traversal follows NLR (node,left,right)
#include<iostream>
using namespace  std;

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

    // creating a node for this inputed data
    root = new treeNode(data);

    if(data == -1) return NULL;

    // taking input data of left & right childs of each node

    cout<<"Enter data of left node of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right node of "<<data<<endl; 
    root->right = buildTree(root->right);

    return root;
}

// funct to execute preorder traversal --> follows NLR (node,left,right)
void preOrderTraversal(treeNode *root){
    
    treeNode *node = root;

    // base case
    if(node == NULL){
        return;
    }

    // NLR 
    cout<<node->data<<" ";          // print data of node
    preOrderTraversal(node->left);  // go to left node of current node
    preOrderTraversal(node->right); // go to right node of current node
}

int main(){

    // creating a root pointing towards NULL initially
    treeNode *root = NULL;

    // building a tree from root
    root = buildTree(root);

    cout<<"Preorder Traversal fashion: ";
    preOrderTraversal(root);

    return 0;
}