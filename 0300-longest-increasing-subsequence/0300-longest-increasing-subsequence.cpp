class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>sorted_arr;
        sorted_arr.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>sorted_arr.back())
            {
                sorted_arr.push_back(nums[i]);
            }
            else{
                int index = lower_bound(sorted_arr.begin(),sorted_arr.end(),nums[i]) - sorted_arr.begin();
                sorted_arr[index]  = nums[i];
            }
        }
        
        return sorted_arr.size();
    }
};