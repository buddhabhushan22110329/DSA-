// if graph is one-based indexing -> make vector of size n+1 (else of size n)
// its like preorder
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &ans, vector<bool> &vis, unordered_map<int,vector<int> >&adj){

    ans.push_back(node);
    vis[node]=1;
    vector<int>temp = adj[node];
    
    for(int i=0; i<temp.size(); i++){
        if(!vis[temp[i]]){
            dfs(temp[i],ans,vis,adj);
        }
    }

}

int main(){
    int n,m; 
    cin>>n>>m;
    bool directed = 0;
    vector<int>ans;

    unordered_map<int,vector<int> >adj;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }

    vector<bool>vis(n,0);
    vis[0]=1;           // mark starting node as visited
    dfs(0,ans,vis,adj);

    for(auto &i:ans) cout<<i<<" ";

    return 0;
}    