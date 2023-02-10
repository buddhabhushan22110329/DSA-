// no, of provinces means no. of connected components

class Solution {
private:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
        vis[node]=1;
        vector<int>v=adj[node];

        for(auto &i:v){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int> >adj;

        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool>vis(isConnected.size()+1, 0);
        int cnt=0;

        for(int i=1; i<=isConnected.size(); i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;
    }
};