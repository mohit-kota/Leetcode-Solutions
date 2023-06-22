class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n,0);
        int i = n-1;
        int begin = 0;
        int end = n-1;
        
        while(i>=0)
        {
            if(nums[begin]*nums[begin]>nums[end]*nums[end])
            {
                ans[i] = nums[begin]*nums[begin];
                i = i-1;
                begin = begin + 1;
            }
            else
            {
                ans[i] = nums[end]*nums[end];
                i = i -1 ;
                end = end - 1;
            }
        }
        
        return ans;
        
    }
};