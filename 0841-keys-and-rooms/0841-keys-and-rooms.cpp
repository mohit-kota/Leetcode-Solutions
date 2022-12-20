class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<int>vis(n,0);
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        
        while(!q.empty())
        {
            auto vec = rooms[q.front()];
            q.pop();
            
            for(auto it : vec)
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        for(auto it : vis)
        {
            if(it==0)
            {
                return false;
            }
        }
        return true;
    }
};