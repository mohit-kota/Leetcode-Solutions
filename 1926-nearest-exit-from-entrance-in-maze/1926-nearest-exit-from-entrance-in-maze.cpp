class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        // point , no of exits at that point
        queue<pair<vector<int>,int>>q;
        
        int row = maze.size();
        int col = maze[0].size();
        q.push({entrance,0});
        int dirx[4] = {0,0,1,-1};
        int diry[4] = {1,-1,0,0};
        
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty())
        {
            auto val = q.front();
            q.pop();
            
            auto vec = val.first;
            auto ext = val.second;
            
            for(int i=0;i<4;i++)
            {
                int nextx = vec[0] + dirx[i];
                int nexty = vec[1] + diry[i];
                
                if(nextx>=0 and nextx<row and nexty>=0 and nexty<col and maze[nextx][nexty]=='.')
                {
                    if(nextx==0 or nextx==row-1 or nexty==0 or nexty==col-1)
                    {
                        return ext+1;
                    }
                    maze[nextx][nexty] = '+';
                    vector<int>arr;
                    arr.push_back(nextx);
                    arr.push_back(nexty);
                    q.push({arr,ext+1});
                }
                
                
            }
        }
        
        return -1;
    }
};