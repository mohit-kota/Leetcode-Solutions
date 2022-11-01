class Solution {
public:
    // 1 means move one row down and right of current position 
    //-1 means move one row down and left  of current position 
    
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(i==grid.size())
        {
            return j;
        }
        
        int nextcolumn = j + grid[i][j];
        
        if(nextcolumn<0 or  nextcolumn>grid[0].size()-1 or grid[i][j]!=grid[i][nextcolumn])
        {
            return -1;
        }
        
        return  dfs(grid,i+1,nextcolumn);
        
        
    }
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
        // ans of size col 
        vector<int>ans(col,0);
        
        //map<pair<int,int>,vector<int>>vis;
        // map<pair<int,int>,int>vis;
        
        //doing bfs on each ball
        for(int i=0;i<col;i++)
        {
             ans[i] = dfs(grid,0,i);
        }
        
        return ans;
        
    }
};