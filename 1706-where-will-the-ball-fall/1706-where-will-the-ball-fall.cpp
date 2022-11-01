class Solution {
public:
    // 1 means move one row down and right of current position 
    //-1 means move one row down and left  of current position 
    
    int dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
    {
        if(i==grid.size())
        {
            return j;
        }
        
        if(dp[i][j]!=-2)
        {
            return dp[i][j];
        }
        int nextcolumn = j + grid[i][j];
        
        if(nextcolumn<0 or  nextcolumn>grid[0].size()-1 or grid[i][j]!=grid[i][nextcolumn])
        {
            return dp[i][j] =  -1;
        }
        
        return dp[i][j] = dfs(grid,i+1,nextcolumn,dp);
        
        
    }
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
        // ans of size col 
        vector<int>ans(col,0);
        
        vector<vector<int>>dp(row+1,vector<int>(col+1,-2));
        // map<pair<int,int>,int>vis;
        
        //doing bfs on each ball
        for(int i=0;i<col;i++)
        {
             ans[i] = dfs(grid,0,i,dp);
        }
        
        return ans;
        
    }
};