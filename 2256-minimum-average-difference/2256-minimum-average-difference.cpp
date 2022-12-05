class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long>prefix(n,0) ;
        
        
        // for prefix sum
        long long total_sum = 0;
        prefix[0] = nums[0];
        total_sum+=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
            total_sum+=nums[i];
        }
        
        int mini = INT_MAX;
        int index = -1;
        for(int i=0;i<n;i++)
        {
            int left = i+1;
            int right = n - i-1;
            long long  left_sum = prefix[i]/left;
            long long  right_sum = 0;
            if(right!=0) {
                right_sum = (total_sum-prefix[i])/right;
            }
            
            
            if(mini>abs(left_sum-right_sum))
            {
                mini = abs(left_sum-right_sum);
                index = i;
            };
        }
        
        return index;
    }
};