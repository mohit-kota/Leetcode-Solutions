class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) 
    {
        
        // ideaology num1 = 2^i + num2 
        
        // for n operations num1 = (2^i1 --- ) + n*num2
        // let diff = 2^i1...
        
        for(int cnt = 1; cnt<60;++cnt)
        {
            long long  diff = num1 - (cnt * num2);
            if(__builtin_popcountll(diff)<=cnt && cnt<=diff)
            {
                return cnt;
            }
        }
        
        return -1;
        
        
    }
};