class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>countsquares(n+1,INT_MAX);
        countsquares[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                countsquares[i] = min(countsquares[i],countsquares[i-j*j]+1);
            }
        }
        
        return countsquares.back();
    }
};