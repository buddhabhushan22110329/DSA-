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

// funct for diameter
int diameter(treeNode *root, int &maxi){

    // base case
    if(root == NULL){
        return 0;
    }

    int lh = diameter(root->left, maxi);
    int rh = diameter(root->right, maxi);

    // int temp = 
    maxi = max(maxi, lh +1+ rh);
    int maxHeight = max(lh, rh) + 1;
    
    return maxHeight;
}

int main(){

    // creating a root jo null ko point kr raha hoga
    treeNode *root = NULL;

    // building tree from root
    root = buildTree(root);

    cout<<"Diameter of binary tree is: ";
    int maxi = INT_MIN;
    diameter(root, maxi);
    cout<<maxi;


    return 0;
}