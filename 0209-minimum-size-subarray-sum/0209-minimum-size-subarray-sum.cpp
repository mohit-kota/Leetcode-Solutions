class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
//         int n    = nums.size(); 
//         int low  = 1;
//         int high = n+1;
//         bool answer = false;
//         while(low<high)
//         {
//             int mid = (low+high)>>1;
//             int max_sum = -1;
//             int sum = 0;
//             for(int i=0;i<mid;i++)
//             {
//                 sum = sum + nums[i];
//             }
//             max_sum = max(max_sum,sum);
//             for(int i=mid;i<n;i++)
//             {
//                 sum = sum - nums[i-mid];
//                 sum = sum + nums[i];
//                 max_sum = max(max_sum,sum);
//             }
            
//             if(max_sum>=target)
//             {
//                 answer = true;
//                 high = mid;
//             }
//             else
//             {
//                 low = mid+1;
//             }
//         }
//         if(answer) return low;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int min_len = INT_MAX;
        while(i<n)
        {
            sum = sum + nums[i];
            while(sum>=target)
            {
                min_len = min(min_len,i-j+1);
                sum = sum - nums[j++];
            }
            i = i+1;
        }
        
        return min_len==INT_MAX?0:min_len;
    }
};