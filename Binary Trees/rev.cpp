#include<iostream>
using namespace std;

// class for TreeNode
class TreeNode{
public:

    int data;
    TreeNode* left;
    TreeNode* right;

    //cons
    TreeNode(int d){
        this->data = d;
        this->left=NULL;
        this->right=NULL;
    }
};

// funct to create tree nodes
TreeNode *buildTree(TreeNode* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    // create a node for this
    root = new TreeNode(data);

    if(data==-1) return NULL;

    // accept data for left & right nodes
    cout<<"Enter data for left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right child of "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

// fun for postOrder traversal
void postOrder(TreeNode *root){     // Left-->Right-->Node

    TreeNode* node =root;

    // base case
    if(node==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<node->data<<" ";
}

// fun for inorder traversal  Left-Node-Right
void inOrder(TreeNode *root){
    TreeNode *temp=root;

    if(temp==NULL) return;

    inOrder(temp->left);
    cout<<temp->data<<" ";
    inOrder(temp->right);
}

// fun for preOrder traversal   Node-Left-right
void preOrder(TreeNode *root){
    TreeNode *temp=root;

    // base case
    if(temp==NULL){
         return;
    }

    cout<<temp->data<<" ";
    preOrder(temp->left);
    preOrder(temp->right);

}   //3 5 7 -1 -1 2 -1 -1 7 8 -1 -1 9 -1 -1

int maxHeight(TreeNode *root){
    // base case
    if(root==NULL) return 0;

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    int ans = max(lh,rh) + 1;
    return ans;
}

int main(){

    // create a root node & initilize it with NULL
    TreeNode *root =NULL;

    root = buildTree(root);
    // postOrder(root);
    //inOrder(root);
    //preOrder(root);
    maxHeight(root);

    return 0;
}