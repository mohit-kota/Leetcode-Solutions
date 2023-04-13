class Solution {
public:
    bool isPrime(int n) {

  if (n <= 1) {
    return false;
  }

  for (int i = 2; i*i <=n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}
    int diagonalPrime(vector<vector<int>>& nums) 
    {
        int maxi = INT_MIN;
        int row = nums.size();
        int cols = nums[0].size();
        for(int i=0;i<row;i++)
        {
                if(isPrime(nums[i][i]))
                {
                    
                    maxi = max(maxi,nums[i][i]);
                    
                 }
            if(isPrime(nums[i][row-i-1]))
            {
                maxi = max(maxi,nums[i][row-i-1]);
            }
        }
        return maxi==INT_MIN?0:maxi;
    }
};