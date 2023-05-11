class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        
        int n = nums.size();
        int pairs=0;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]-k])
            {
                pairs+=mp[nums[i]-k];
            }
        }
        return pairs;
    }
};