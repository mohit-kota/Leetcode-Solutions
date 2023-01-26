class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        int stops = 0;
        
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        
        while(stops<=k && !q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto [node,distance] = q.front();
                q.pop();
                
                for(auto& [neighbour,price]:adj[node])
                {
                    if(price+distance<=dist[neighbour])
                    {
                        dist[neighbour] = price + distance;
                        q.push({neighbour,dist[neighbour]});
                    }
                }
            }
            stops++;
        }
        
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};