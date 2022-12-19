class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) 
    {
        vector<int> adj[n];
        // mapping of all edges 
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>vis(n,0); // visited check
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            if(node==dst)
            {
                return true;
            }
            
            for(auto i:adj[node])
            {
                if(!vis[i])
                {
                    q.push(i);
                    vis[i]=1;
                }
            }
         }
        return false;
    }
};