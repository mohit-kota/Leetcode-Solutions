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
        
        vector<vector<int>>dp(row+1,vector<int>(col,0));
        // map<pair<int,int>,int>vis;
        
        //doing bfs on each ball
        // for(int i=0;i<col;i++)
        // {
        //      ans[i] = dfs(grid,0,i,dp);
        // }
        
        // tabulation 
        
        for(int i=row;i>=0;i--)
        {
            for(int j=0;j<col;j++)
            {
                if(i==grid.size())
                {
                    dp[i][j] = j;
                    continue;
                }
                
                int nextcolumn = j + grid[i][j];
        
                if(nextcolumn<0 or  nextcolumn>grid[0].size()-1 or grid[i][j]!=grid[i][nextcolumn])
                {
                    dp[i][j] =  -1;
                }
                else{
                dp[i][j] = dp[i+1][nextcolumn];
                }
            }
        }
        vector<int>ans1(dp[0].begin(),dp[0].end());
        return ans1;
        
    }
};