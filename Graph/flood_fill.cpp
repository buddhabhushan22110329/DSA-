class Solution {
private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans, int sr, int sc, int &color, int old){
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        // 4 directions
        
        if(sr<n && sr>=0 && sc-1<m && sc-1>=0 && image[sr][sc-1]==old && ans[sr][sc-1]!=color){
            dfs(image,ans,sr,sc-1,color,old);
        }
        if(sr<n && sr>=0 && sc+1<m && sc+1>=0 && image[sr][sc+1]==old && ans[sr][sc+1]!=color){
            dfs(image,ans,sr,sc+1,color,old);
        }
        if(sr-1<n && sr-1>=0 && sc<m && sc>=0 && image[sr-1][sc]==old && ans[sr-1][sc]!=color){
            dfs(image,ans,sr-1,sc,color,old);
        }
        if(sr+1<n && sr+1>=0 && sc<m && sc>=0 && image[sr+1][sc]==old && ans[sr+1][sc]!=color){
            dfs(image,ans,sr+1,sc,color,old);
        }

    }    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>ans=image;

        int old=image[sr][sc];
        //cout<<old<<endl;
        dfs(image,ans,sr,sc,color,old);
        return ans;
    }
};