class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int ans = 1;
        int n = nums.size();
        int j = 0;
        multiset<int>ms;
        for(int i=0;i<n;i++)
        {
            ms.insert(nums[i]);
            while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit)
            {
                ms.erase(ms.find(nums[j++]));
            }
            
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};