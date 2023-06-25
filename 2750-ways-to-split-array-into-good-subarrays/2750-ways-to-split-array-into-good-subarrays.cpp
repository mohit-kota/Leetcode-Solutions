class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        int mod = 1e9+7;
        int n = nums.size();
        
        long long zeroes = 0;
        long long res = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                res =  res ? (res * (zeroes+1))%mod : 1;
                zeroes = 0;
            }
            else{
                zeroes += res>0;
            }
        }
        
        return res;
    }
};