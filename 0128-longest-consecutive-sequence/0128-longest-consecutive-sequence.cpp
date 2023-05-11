class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int>myset;
        for(auto i:nums)
        {
            myset.insert(i);
        }
        //int len=0;
        int maxlen=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            if(myset.count(ele-1)==0)
            {
                int len=1;
                //ele=ele+1;
                while(myset.count(ele+1)>0)
                {
                    ele=ele+1;
                    len+=1;
                }
                maxlen=max(len,maxlen);
            }
            
        }
        return maxlen;
    }
};