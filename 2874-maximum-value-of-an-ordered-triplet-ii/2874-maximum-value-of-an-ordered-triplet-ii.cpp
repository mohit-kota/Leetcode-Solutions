class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long>prefix_max(n,0);
        vector<long long>suffix_max(n,0);
        
        for(int i = 0; i< n;i++)
        {
            long long a = (long long)nums[i]; // front
           
            if(i==0)
            {
                prefix_max[i] = max(prefix_max[i],a);
            
            }
            else{
                 prefix_max[i] = max(prefix_max[i-1],a);
           
            } 
        }
        for(int i = n-1; i>=0;i--)
        {
            long long a = (long long)nums[i]; // front
           
            if(i==n-1)
            {
                suffix_max[i] = max(suffix_max[i],a);
            
            }
            else{
                 suffix_max[i] = max(suffix_max[i+1],a);
           
            } 
        }
       
      
        long long answer = 0;
        for(int i=1;i<n-1;i++)
        {
            long long a = (long long)prefix_max[i-1]; // front
            long long b = (long long)suffix_max[i+1]; // back
            long long c = (long long) nums[i];
            answer = max(answer , (a-c)*b);
        }
        return answer;
        
        
        
    }
};