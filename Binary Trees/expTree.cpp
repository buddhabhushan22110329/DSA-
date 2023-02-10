#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class eTree{
public:
    char val;
    eTree* left;
    eTree* right;

    //cons
    eTree(char val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

};

void inorder(eTree* &root){
    // base case
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){

    string exp = "dyggxxpklorellnmp*+^*^^/+*/-//^/-";
    stack<eTree*>s;

    for(auto &i:exp){
        if(i>='a' && i<='z'){
            eTree* ch = new eTree(i);
            s.push(ch);
        }

        else{
            eTree* n1 = s.top(); s.pop();
            eTree* n2 = s.top(); s.pop();
            eTree* root = new eTree(i);
            root->left=n2;
            root->right=n1;
            s.push(root);
        }
    }

    eTree* root = s.top();

    inorder(root);

    return 0;
}