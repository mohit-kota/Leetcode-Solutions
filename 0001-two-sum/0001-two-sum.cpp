class Solution {
public:
    
    void findsum(vector<int>&answer,vector<int>nums,int target){
        unordered_map<int,int>mp;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            int diff = target-nums[i];
            if(mp.find(diff)!=mp.end())
            {
                answer.push_back(i);
                answer.push_back(mp[diff]);
                return ;
            }
            mp[nums[i]] = i;
        }
    }
    
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>answer;
        findsum(answer,nums,target);
        return answer;
    }
};