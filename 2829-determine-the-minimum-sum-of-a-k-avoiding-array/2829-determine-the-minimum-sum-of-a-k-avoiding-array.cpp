class Solution {
public:
    int minimumSum(int n, int k) 
    {
        vector<int>arr(n,0);
        map<int,int>mp;
        
        int i = 1;
        int j = 0;
        int sum = 0;
        while(j<n)
        {
            if(!mp[k-i])
            {
                mp[i]++;
                sum += i;
                arr[j++] = i++; 
            }
            else{
                i++;
            }
            
        }
        return sum;
    }
};