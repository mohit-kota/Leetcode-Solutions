class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n+5,vector<int>(n+5,0));
        vector<int>g(n+2,1);
        int  i = 1;
        for(int k=1;k<=n;k++)
        {
            g[k] = nums[k-1];
        }
        
        
        // for length 1
        while(i<=n){
            dp[i][i] = g[i-1]*g[i]*g[i+1];
            i = i+1;
        }
        
        for(int len=2;len<=n;len=len+1)
        {
            for(int i=1;i<=n-len+1;i++)
            {
                int j = i+len-1;
                
                int k = i;
                int ll = INT_MIN;
                for(k=i;k<=j;k++)
                {
                    int possibility = g[i-1]*g[k]*g[j+1];
                    
                    if(i<=k-1)
                    {
                        possibility+=dp[i][k-1];
                    }
                    
                    if(k+1<=j){
                        possibility+=(dp[k+1][j]);
                    }
                    
                     ll = max(ll,possibility);
                
                }
                dp[i][j] = ll;
            }
        }
        
        return dp[1][n];
        
    }
};