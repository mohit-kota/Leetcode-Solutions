class Solution {
public:
    vector<int>prime;
    void calculateprimes(int n)
    {
       
        //memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }            

    }
    vector<vector<int>> findPrimePairs(int n) 
    {
        prime.resize(n+1,true); 
        calculateprimes(n);
        vector<vector<int>>ans;
        for(int i=2;i<=(n/2);i++)
        {
            if(prime[i] && prime[n-i])
            {
                ans.push_back({i,n-i});
            }
        }
        return ans;
        
    }
};