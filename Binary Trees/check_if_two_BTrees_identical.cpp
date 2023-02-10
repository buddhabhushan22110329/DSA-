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

// funct to check if identical or not
bool isIdentical(treeNode *root1, treeNode *root2){

    // base case
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL && root2 != NULL) return false;
    if(root1 != NULL && root2 == NULL) return false;

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool ans = root1->data == root2->data;

    if(left && right && ans) return true;
    else return false;

}

int main(){

    // creating a root jo null ko point kr raha hoga
    treeNode *root1 = NULL;
    treeNode *root2 = NULL;

    // building tree from root
    root1 = buildTree(root1);
    root2 = buildTree(root2);

    if(isIdentical(root1, root2) == true) cout<<"Trees are identical"<<endl;
    if(isIdentical(root1, root2) == false) cout<<"Trees are not identical"<<endl;



    return 0;
}