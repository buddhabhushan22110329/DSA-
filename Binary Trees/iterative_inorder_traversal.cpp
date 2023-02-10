// inorder follows --> LNR (Left Node Right)

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

// funct for iterative inorder traversal
void iterative_inorder(treeNode *root){

    // creating a stack of treeNode data type to push elements in LIFO order
    stack<treeNode*> s;

    // creating a vector to store ans
    vector<int> ans;

    treeNode *node = root;
    while(1){

        if(node != NULL){
            s.push(node);
            node = node->left;              // L
        }

        else{
            if(s.empty()) break;
            node = s.top();
            ans.push_back(node->data);      // N
            s.pop();
            node = node->right;             // R
        }
    }

    // printing ans vector
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
   
}

int main(){

    // creating a root jo null ko point kr raha hoga
    treeNode *root = NULL;

    // building tree from root
    root = buildTree(root);

    iterative_inorder(root);

    return 0;
}