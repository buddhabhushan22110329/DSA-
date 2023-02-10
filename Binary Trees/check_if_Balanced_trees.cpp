// A binary tree's diameter is max(leftHeight+rightHeight) for each node
// eka node pasun dusrya node pryntcha largest distance la diameter mhntat

// If u r not doing it on paper then dont expect anything frm yourSelf

#include<iostream>
#include<climits>
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

// funct for height of binary tree
int height(treeNode *root){

    // base case
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int maxHeight = max(leftHeight, rightHeight) + 1;
    return maxHeight;
}

// funct to check if tree is balanced or not
bool balanced(treeNode *root){

    // base case
    if(root == NULL) return true;

    bool lh = balanced(root->left);
    bool rh = balanced(root->right);

    // now check difference of height of left wala subTree & right wala subTree 

    bool differenceOfHeight = abs( height(root->left) - height(root->right) ) <= 1;

    if(lh && rh && differenceOfHeight) return true;
    else return false;
   
}

int main(){

    // creating a root jo null ko point kr raha hoga
    treeNode *root = NULL;

    // building tree from root
    root = buildTree(root);

    if(balanced(root) == true) cout<<"Tree is balanced"<<endl;
    if(balanced(root) == false) cout<<"Tree is not balanced"<<endl;


    return 0;
}