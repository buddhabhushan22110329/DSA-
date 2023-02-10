// postorder follows --> LRN (Left Right Node)
// using two stack

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
void iterative_postorder(treeNode *root){

    // creating a stack of treeNode data type to push elements in LIFO order
    stack<treeNode*> s1, s2;

    // creating a vector to store ans
    vector<int> ans;

   s1.push(root);
   treeNode *node = root;

   while(!s1.empty()){
    node = s1.top();
    s2.push(node);
    s1.pop();

    if(node->left != NULL) s1.push(node->left);      // L
    if(node->right != NULL) s1.push(node->right);    // R

   }

   // s2 ke sare elements ans vet me store kro aur phir ans vect ko print kro
   while(!s2.empty()){
    ans.push_back(s2.top()->data);
    s2.pop();
   } 

   // printing ans vector
   cout<<"Iterative Postorder is:  ";
   for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
   }
   
}

int main(){

    // creating a root jo null ko point kr raha hoga
    treeNode *root = NULL;

    // building tree from root
    root = buildTree(root);

    iterative_postorder(root);


    return 0;
}