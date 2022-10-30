class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        // use bfs 
        
        int dirx[4] = {-1,1,0,0};
        int diry[4] = {0,0,1,-1};
        
        
        queue<vector<int>>q;
        // queue is of form of (x,y,k)
        
        // x , y , k , steps
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,-1));
        q.push({0,0,k,0});
        while(!q.empty())
        {
            auto vec = q.front();
            int x = vec[0];
            int y = vec[1];
            int ob = vec[2];
            int steps = vec[3];
            q.pop();
            
            if(x==row-1 and y==col-1)
            {
                return steps;
            }
            
            // valid
            if(x>=0 and y>=0 and x<row and y<col)
            {
                if(grid[x][y]==1)
                {
                    if(ob>0)
                    {
                        ob--;
                    }
                    else
                    {
                        continue;
                    }
                }
                
                
                if(vis[x][y]==-1 or vis[x][y]<ob)
                {
                    vis[x][y] = ob;
                    for(int i=0;i<4;i++)
                    {
                        q.push({x+dirx[i],y+diry[i],ob,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};