class Solution {
public:
//     int shortestSubarray(vector<int>& nums, int k) 
//     {
//         deque<long>dq;
//         int n = nums.size();
//         int res = n+1;
//         for(int i=0;i<n;i++)
//         {
//             if(i>0)
//             {
//                 nums[i] = nums[i] + nums[i-1];
//             }
            
//             if(nums[i]>=k)
//             {
//                 res = min(res,i+1);
//             }
            
            
//             // this while loop is used for getting minimal length till sum>=k
//             while(!dq.empty() && nums[i]-nums[dq.front()]>=k)
//             {
//                 res = min(res,i-dq.front());
//                 dq.pop_front();
//             }
            
//             // this while lop is used for maintaining the queue in increasing order 
//             while(!dq.empty() && nums[i]<=nums[dq.back()]){
//                 dq.pop_back();
//             }
            
//             dq.push_back(i);
            
//         }
        
//         return res<=n?res:-1;
//     }
    int shortestSubarray(vector<int> A, int K) {
        int N = A.size(), res = N + 1;
        vector<long long>B(N,0);
        for(int i=0;i<N;i++)
        {
            B[i] = (long long)A[i];
        }
        deque<long long> d;
        for (int i = 0; i < N; i++) {
            if (i > 0)
                B[i] += B[i - 1];
            if (B[i] >= K)
                res = min(res, i + 1);
             // this while loop is used for getting minimal length till sum>=k
            while (d.size() > 0 && B[i] - B[d.front()] >= K)
            {
                
                if(res > i-d.front())
                {
                    res = i - d.front();
                   
                }
                 d.pop_front();
            }
            // this while lop is used for maintaining the queue in increasing order 
            while (d.size() > 0 && B[i] <= B[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};