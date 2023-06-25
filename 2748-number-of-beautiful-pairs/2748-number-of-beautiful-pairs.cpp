class Solution {
public:
    int reverse(int n)
    {
        int rev = 0;
        while(n!=0)
        {
            int rem = n%10;
            rev = rev*10 + rem;
            n = n/10;
        }
        return rev%10;
    }
    int countBeautifulPairs(vector<int>& nums) 
    {
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            {
                int x = reverse(nums[i]);
                int y = nums[j]%10;
                
                if(__gcd(x,y)==1)
                {
                // cout<<x<<" "<<y<<endl;
                    count = count + 1;
                }
            }
        }
        return count;
    }
};