class Solution {
public:
    int getsumofdivsquares(int n,vector<int>nums){
        
        int sum = 0;
        
        for(int j=1;j*j<=n;j++){
            if(n%j==0){
                // cout<<j<<endl;
                sum = sum + pow(nums[j-1],2);
                if(j!=(n/j))
                    // cout<<(n/j)<<endl;
                  sum = sum + pow(nums[(n/j)-1],2);
            }
        }
        
        return sum;
        
        
}
    int sumOfSquares(vector<int>& nums) 
    {
      return getsumofdivsquares(nums.size(),nums);
        return 0;
    }
};