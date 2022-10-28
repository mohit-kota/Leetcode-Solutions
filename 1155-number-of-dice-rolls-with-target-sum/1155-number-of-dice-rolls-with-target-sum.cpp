class Solution {
public:
    int mod = 1e9+7;
    int recursion (int ind,int k,int tgt,vector<vector<int>>&dp)
    {
        
        if(tgt<0)
        {
            return 0;
        }
        if(ind==0)
        {
            if(tgt==0)
            {
                return 1;
            }
            
            return 0;
        }
        if(dp[ind][tgt]!=-1)
        {
            return dp[ind][tgt];
        }
        int step = 0;
        for(int i=1;i<=k;i++)
        {
            step=step%mod + recursion(ind-1,k,tgt-i,dp)%mod;
            step = step%mod;
        }
        
        return dp[ind][tgt]=step%mod;
    }
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>>dp(31,vector<int>(1001,-1));
        return recursion(n,k,target,dp);    
    }
};