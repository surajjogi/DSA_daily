class Solution {
public:
    int dfs(int n,int m,vector<vector<bool>>&visited,vector<vector<int>>& grid,int i,int j,int maxArea){
       if(i < 0 || j < 0 || i >= n || j >= m ||
   visited[i][j] || grid[i][j] != 1){
        return maxArea;
       }
       visited[i][j]=true;
       maxArea++;
    maxArea = dfs(n, m, visited, grid, i - 1, j, maxArea);
        maxArea = dfs(n, m, visited, grid, i + 1, j, maxArea);
        maxArea = dfs(n, m, visited, grid, i, j + 1, maxArea);
        maxArea = dfs(n, m, visited, grid, i, j - 1, maxArea);
       return maxArea;
       
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       int maxArea = 0;
        int ans=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  maxArea=0;
               ans=max(ans,dfs(n,m,visited,grid,i,j,maxArea));
            }
        }
       return ans;
    }
};