class Solution {
public:
    
    int longestAlternatingSubarray(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        int max_len = 0;
        int last = INT_MAX;
        if(nums[0] <= threshold && nums[0] % 2 == 0) last = 0;
        int j = 1;
        while(j<n)
        {
            if(nums[j]>threshold || ((nums[j] % 2) == (nums[j-1] % 2)))
            {
                max_len = max(max_len,j-last);
                last = INT_MAX;
            }
            if(last==INT_MAX && nums[j]<=threshold && nums[j]%2==0)
            {
               last = j;
            }
            j = j+1;
        }
        max_len = max(max_len,j-last);
        return max_len;
    }
};