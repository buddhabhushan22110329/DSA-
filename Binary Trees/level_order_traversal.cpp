#include<iostream>
#include<vector>
#include<queue>
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

// funct to create tree
treeNode *buildTree(treeNode *root){
    int data;
    cout<<"Enter data: ";
    cin>>data;

    // creating a node for this data
    root = new treeNode(data);

    if(data == -1) return NULL;

    // take input data for left & right childs of each node
    
    cout<<"Enter data of left child of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data of right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

// funct to print nodes level wise
vector<vector<int>> levelOrder(treeNode *root){

    vector<vector<int>> ans;        // like a 2D array to store nodes level wise
    
    if(root == NULL) return ans; // tree ka root hi agar NULL hai toh empty vector ans print hoga

    queue<treeNode*> q;     // treeNode* dataType ka ek queue bana diya
    q.push(root);           // tree ke root ko as it is push kro queue me

    while(!q.empty()){
        int size = q.size();
        vector<int> level;     // har level ke nodes ke data ko store krne ke liye

        for(int i=0; i<size; i++){
            
            treeNode *node = q.front(); // front node ko node naam ke var me store kiya jiska dataType treeNode* hai

            level.push_back(node->data); //front wale node ka data store kiya level me
            q.pop();

            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);

        }

        // yaha pahuch gaye mtlb ki queue empty hogayi hai, mtlb ki ek particular level complete hogaya hai aur us particular level ke nodes ka data level vector me store hai... ab us level vector ko ans vec of vec me store kro 
        ans.push_back(level);
    }

    cout<<endl;

    // printing vec of vec ans
    for(int i=0; i<ans.size(); i++){
        cout<<"Level "<<i<<"  ";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return ans;
}

int main(){

    // creating root jo starting me NULL ko point krega
    treeNode *root = NULL;

    // creating a tree
    root = buildTree(root);

    // we want to print nodes level wise like this--> 3          level 0
    //                                                5 7        level 1
    //                                                1 2 8 9    level 2

    // we will use a queue, vec<vec<int> ans, vec<int> level for this

    // calling funct
    levelOrder(root);

    return 0;
}