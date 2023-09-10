class Solution {
public:
    static bool  comp(const vector<int> &a,const vector<int> &b)
    {
          if(a[0]==b[0])
          {
              return a[1]<b[1];
          }
          return a[0]<b[0];
    }
    int numberOfPoints(vector<vector<int>>& nums) 
    {
         sort(nums.begin(),nums.end(),[](auto &a,auto &b){
          if(a[0]==b[0])
          {
              return a[1]<b[1];
          }
          return a[0]<b[0];
         });
        // for(auto it : nums)
        // {
        //     for(auto j : it)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int low = nums[0][0] , high = nums[0][1];
        int p = 0;
        // cout<<low<<" "<<high<<endl;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i][0]<=high)
            {
                high = max(high,nums[i][1]);
            }
            else{
                p += high - low + 1;
                low = nums[i][0];
                high = nums[i][1];
            }
            // cout<<low<<" "<<high<<endl;
        }
        p+= high-low+1;
        
        return p;
    }
};