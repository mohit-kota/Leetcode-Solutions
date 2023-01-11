class Solution {
public:
    int get(int node,int par,vector<vector<int>>&adj,vector<bool>&hasApple)
    {
        int totaltime = 0,childtime = 0;
        for(auto it : adj[node])
        {
            if(it==par)
            {
                continue;
            }
            childtime=get(it,node,adj,hasApple);
            
            if(childtime || hasApple[it])
            {
                totaltime+=childtime+2;
            }
        }
        return totaltime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)          
    {
        vector<vector<int>>adj(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return get(0,-1,adj,hasApple);
    }
};
