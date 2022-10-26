class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        int n = nums.size();
        int runningsum = 0;
        for(int i=0;i<n;i++)
        {
            runningsum+=nums[i];
            
            if(k!=0)
            {
                //cout<<"sum "<<runningsum<<endl;
                 runningsum%=k;
                //cout<<"rem "<<runningsum<<endl;
            }
            if(runningsum==0 and i) return true;
            if(mp.find(runningsum)!=mp.end())
            {
                if(i-mp[runningsum]>1)
                {
                    return true;
                }
            }
            else
            {
                mp[runningsum] = i;
            }
        }
        return false;
    }
};