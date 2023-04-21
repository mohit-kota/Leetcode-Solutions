class Solution {
public:
    // Time Complexetiy : O(n)
    // Space Complexity : O(n)
    
    // Undordered_map find() tc is O(1)
    // if ordered map then O(log(n))
    
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