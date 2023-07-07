class Solution {
public:
    
    int countSubstrings(string s) 
    {
        
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
       
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            ans++;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=n-i;j++)
            {
                int k=j+i-1;
                if(i==2 and s[j]==s[k])
                {
                    dp[j][k]=1;
                    ans++;
                }
                else if(s[j]==s[k] and dp[j+1][k-1])
                {
                    dp[j][k]=1;
                    ans++;
                }
                
            }
        }
       
        return ans;
    }
};