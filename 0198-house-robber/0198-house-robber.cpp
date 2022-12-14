class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int prev1,prev2;
        prev1=nums[0];
        int n=nums.size();
        if(n==1)
        {
            return prev1;
        }
        prev2=max(prev1,nums[1]);
        int ans = prev2;
        for(int i=2;i<n;i++)
        {
            ans=max(prev2,prev1+nums[i]);
            prev1=prev2;
            prev2=ans;
        }
        return prev2;
    }
};