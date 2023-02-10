#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    //cons
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// funct to create tree
node *buildTree(node *root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    // creating a node for this inputed data
    root = new node(data);

    if(data == -1) return NULL;

    // take input for left & right childs of each node
    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

int main(){

    // creating root pointing towards null
    node *root = NULL;

    root = buildTree(root);


    return 0;
}