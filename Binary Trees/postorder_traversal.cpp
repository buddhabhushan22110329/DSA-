// Postorder traversal follows LRN (left, right, node)
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

treeNode *buildTree(treeNode *root){

    int data;
    cout<<"Enter data: ";
    cin>>data;

    // creating a node for this data
    root = new treeNode(data);

    if(data == -1) return NULL;

    // taking input for left & right childs of each node

    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void postOrderTraversal(treeNode *root){

    treeNode *node =root;

    // base case
    if(node == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<node->data<<" ";

}

int main(){

    // creating root which will point towards NULL initially
    treeNode *root = NULL;

    // building tree from root
    root = buildTree(root);

    cout<<"Postorder Traversal fashion: ";
    postOrderTraversal(root);

    return 0;
}