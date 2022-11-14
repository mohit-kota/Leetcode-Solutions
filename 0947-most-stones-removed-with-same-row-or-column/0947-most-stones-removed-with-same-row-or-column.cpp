class Solution {
public:
    int dfs(vector<vector<int>>&stones,int ind ,vector<bool>&vis)
    {
        vis[ind] = true;
        int result = 0;
        for(int i=0;i<stones.size();i++)
        {
            if(!vis[i])
            {
                if((stones[i][0]==stones[ind][0]) or stones[i][1]==stones[ind][1])
                {
                    result += 1 + dfs(stones,i,vis);
                }
            }
        }
        return result;
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        vector<bool>vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
            {
                continue;
            }
            ans += dfs(stones,i,vis);
        }
        return ans;
    }
};