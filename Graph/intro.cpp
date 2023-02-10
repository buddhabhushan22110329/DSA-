//Graph: collection of edges & nodes
// Types: UnDirected-> direction of edges is not mentioned
//        Directed-> direction of edges is mentioned
// Weighted graph-> has some values to the edges of graph (if weight is not mentioned then consider weight =1)
// degree of a node: total no of connected edges to a node
// Total degree of UnDirected graph: 2*no of edges
// InDegree of node (in directed graph): total no of edges coming towards it
// OutDegree of node (in directed graph): total no of edges going from it

// Representation: 1. Adjacency matrix  2. List 

#include<iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int adj[n+1][n+1];
    bool directed = false;


    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        if(!directed) adj[v][u]=1;
    }

    return 0;
}