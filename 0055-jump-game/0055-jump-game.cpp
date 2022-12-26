class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        int MaxDis=0;
        for(int i=0;i<=MaxDis&&i<n;i++)
        {
            int currMax=i+nums[i];
            MaxDis=max(MaxDis,currMax);
            
        }
        if(MaxDis>=n-1) 
        {
            return true;
        }
        return false;
    
    }
};