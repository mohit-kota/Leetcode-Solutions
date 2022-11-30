class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int,int>mp;
        int maxi = -1;
        
        for(auto it : arr)
        {
            mp[it]++;
            maxi = max(maxi,mp[it]);
        }
        
        vector<int>vec(maxi+1,-1);
        
        for(auto it : mp)
        {
            if(vec[it.second]!=-1)
            {
                return false;
            }
            vec[it.second] = 0;
        }
        return true;
    }
};