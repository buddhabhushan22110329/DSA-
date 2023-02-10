// A binary tree's minimun depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// If u r not doing it on paper then dont expect anything frm yourSelf

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class treeNode{
public:
    int data;
    treeNode *left;
    treeNode *right;

    //cons
    treeNode(int d){
        this->data = d;
        this->left =NULL;
        this->right =NULL;
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

    // taking input for data of childs of left & right nodes of each node
    
    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// funct for iterative postorder traversal
int MinheightORdepth(treeNode *root){
    
    int ans;

    // base case
    if(root == NULL){
        return 0;
    }

    // left subTree ki height nikalo
    int left = MinheightORdepth(root->left);

    // right subTree ki height nikalo
    int right = MinheightORdepth(root->left);

    if(root->left != NULL && root->right != NULL){
        ans = min(left,right) + 1;
    }
    else{
        ans = max(left,right) + 1;
    }

    return ans;
}

int main(){

    // creating a root jo null ko point kr raha hoga
    treeNode *root = NULL;

    // building tree from root
    root = buildTree(root);

    cout<<"Min Height of binary tree is: ";
    cout<<MinheightORdepth(root);


    return 0;
}