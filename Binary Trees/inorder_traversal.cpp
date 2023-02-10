// Inorder traversal follows LNR (left, node, right)
#include<iostream>      
using namespace std;

class treeNode{
public: 
    int data;
    treeNode* left;
    treeNode* right;

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

    // creating a node for this inputed data
    root = new treeNode(data);
    if(data == -1) return NULL;

    // taking input for data of left & right child of each node
    cout<<"Enter data of left node of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right node of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// funct to print data of node in inorder traversal fashion--> follows LNR (left, node, right)
void inorderTraversal(treeNode *root){

    treeNode *node = root;

    // base case
    if(node == NULL){
        return;
    }

    inorderTraversal(node->left);
    cout<<node->data<<" ";
    inorderTraversal(node->right);

}

int main(){

    // creating root pointing towards null
    treeNode *root = NULL;

    root = buildTree(root);
    cout<<"Inorder Traversal fashion: ";
    inorderTraversal(root);


    return 0;
}