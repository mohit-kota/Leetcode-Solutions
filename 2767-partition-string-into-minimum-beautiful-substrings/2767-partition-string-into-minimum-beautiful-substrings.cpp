class Solution {
public:
    // to get decimal number of i to j
    int getnumber(int i,int j,string s)
    {
        int b = 0;
        int ans = 0;
        while(j>=i)
        {
            if(s[j]=='1')
            {
                ans = ans + pow(2,b);
            }
             b++;
            j--;
            
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s) 
    {
        vector<int>dp(100,100);
        dp[0] = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            int j = i;
            int answer = 100;
            while(j>=0){
                int g = getnumber(j,i,s);
                // cout<<g<<endl;
                if(s[j]!='0' && g!=0 && (15625%g)==0)
                {
                    // cout<<"dp j"<<dp[j]<<endl;
                   answer = min(answer,1+dp[j]);
                }
                j--;
            }
            // cout<<answer<<endl;
            dp[i+1] = answer;
            // break;
        }
        
        return dp[n]==100?-1:dp[n];
    }
};