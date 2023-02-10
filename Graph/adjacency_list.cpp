// For each node store all nodes connected to it (i.e it's neighbours)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int> >adj;
    bool directed = false;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }

    // printing neighbours of each node
    for(auto &x:adj){
        cout<<x.first<<"->";
        for(auto i:x.second){
            cout<<i<<" ";
        }cout<<endl;
    }

    return 0;
}