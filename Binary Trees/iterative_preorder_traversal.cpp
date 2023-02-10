// preorder follows --> NLR (Node Left Right)

// 1. root ko stack me as it is push kro
// 2. ans vect me pushback kro
// 3. node ka right-> data stack me push kro left->data se pehle


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

// funct for iterative preorder traversal
void iterative_preorder(treeNode *root){

    // creating a stack of treeNode data type to push elements in LIFO order
    stack<treeNode*> s;

    // creating a vector to store ans
    vector<int> ans;

    // push root of tree directly into stack
    s.push(root);

    while(!s.empty()){
        treeNode *node = s.top();
        ans.push_back(node->data);
        s.pop();

        if(node->right != NULL) s.push(node->right);
        if(node->left != NULL) s.push(node->left);

    }

    // printing ans vect
    cout<<"Iterative Preorder traversal is: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }




}

int main(){

    // creating a root jo null ko point kr raha hoga
    treeNode *root = NULL;

    // building tree from root
    root = buildTree(root);

    // creating a stack
    stack<int> s;

    iterative_preorder(root);


    return 0;
}