
// "If a subarray is considered good, all the subarray containing this subarray will also be good."
// Ex: [3,1,4,3,2,2,4] that has 3 pairs and [3,1,4,3,2,2] that has 2 pairs. But in both cases [3,1,4,3,2,2] subarray is common if we iterate from i = 0 to i < n this is the first subarray that we will encounter first that satisfies all the condition so this is a good subarray. So All the other subarrays which will contain this will also be good by default. So if you do this res += n - i; it will give you all those subarray's count which will contain this [3,1,4,3,2,2] subarray. If you dry this code on pen and paper , you will understand more.


/*


After reaching a good subarray say A[i ... j] then every subarray A[i ... j + 1] A [i ... j + 2] everything is good.

So if we add n - j we take care of all those good subarrays no need to increase j.

Since we have added all n- j good subarrays i.e [i , j] , [i , j + 1] , [i , j +2] ....
all we have to do is push i forward to find new pair of [i , j]

*/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        // map for storing freq of variable
        map<long long,long long>mp;
        // counter to tract good subbarray
        long long counter = 0;
        long long res = 0;
        long long temp = 0;
        
        int n = nums.size();
        
        int i=0;
        // mp[nums[0]]++;
        for(int j=0;j<n;j++)
        {
            counter = counter + mp[nums[j]];
            mp[nums[j]]++;
            
            while(counter>=k)
            {
                res = res + (n-j); 
                cout<<"at j"<<j<<" "<<(n-j)<<endl;
                counter -= mp[nums[i]]-1;
                mp[nums[i]]--;
                i++;
            }
        }
        
        return res;
        
        
    }
};