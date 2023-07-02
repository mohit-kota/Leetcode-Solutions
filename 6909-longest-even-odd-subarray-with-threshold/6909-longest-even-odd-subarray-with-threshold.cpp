class Solution {
public:
    bool isvalid(int l,int r,vector<int>&nums,int threshold)
    {
        bool con1 = true;
        bool con2 = true;
        if(nums[l]%2!=0)
        {
            return false;
        }
        for(int start=l;start<r;start++)
        {
            if(nums[start]%2==nums[start+1]%2)
            {
                con1=false;
                break;
            }
            if(nums[start]>threshold)
            {
                con2 = false;
                break;
            }
        }
        if(nums[r]>threshold)
        {
            con2 = false;
        }
        return con1&&con2;
    }
    int longestAlternatingSubarray(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        int max_len = 0;
        for(int l=0;l<n;l++)
        {
            for(int r=l;r<n;r++)
            {
                if(isvalid(l,r,nums,threshold))
                {
                    max_len = max(max_len,r-l+1);    
                }
            }
        }
        
        return max_len;
    }
};