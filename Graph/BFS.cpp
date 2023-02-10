// if graph is one-based indexing -> make vector of size n+1 (else of size n)
// its like level order traversal
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; 
    cin>>n>>m;
    bool directed = 0;

    unordered_map<int,vector<int> >adj;
    

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }

    queue<int>q;
    vector<int>bfs;
    vector<bool>vis(n,0);
    q.push(0);
    vis[0]=true;

    while(!q.empty()){
        int node = q.front(); q.pop();
        bfs.push_back(node);
        vector<int> temp = adj[node];
        for(int i=0; i<temp.size(); i++){
            if(!vis[temp[i]]){
                vis[temp[i]]=1;
                q.push(temp[i]);
            }
        }
    }

    for(auto &i:bfs){
        cout<<i<<" ";
    }


    return 0;
}    