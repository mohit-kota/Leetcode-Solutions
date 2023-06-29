class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<int>dq(k);
        int max_index = -1;
        int max_ele = INT_MIN;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
                
            }
            
            dq.push_back(i);

        }
        // dq.push_back(max_index);
        vector<int>ans;
        for(int i=k;i<n;i++)
        {
            ans.push_back(nums[dq.front()]);
            // if removed element is max element
            while(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};