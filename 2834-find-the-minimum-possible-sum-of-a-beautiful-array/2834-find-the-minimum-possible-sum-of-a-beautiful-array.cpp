class Solution {
public:
    long long minimumPossibleSum(int n, int target) 
    {
        int num = 1;
        map<int,int>mp;
        
        long long  answer = 0;
        while(mp.size() < n)
        {
            if(mp.find(target-num)==mp.end())
            {
                // cout<<" test "<<endl;
                answer = answer + num;
                mp[num] = 1;
            }
            num = num +1;
        }
        return answer;
    }
};