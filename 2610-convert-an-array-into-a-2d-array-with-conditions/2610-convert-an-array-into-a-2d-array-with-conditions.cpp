class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        map<int,int>mp;  
        for(auto it : nums)
        {
            mp[it]++;
        }
        
        vector<vector<int>>ans;
        bool flag = true;
        while(true)
        {
            vector<int>dum;
            bool dum2 = false;
            for(auto it : mp)
            {
                if(it.second>0)
                {
                    dum2 = true;
                    dum.push_back(it.first);
                    mp[it.first] = it.second-1;
                }
            }
            if(!dum2)
            {
              break;
            }
            ans.push_back(dum);
            
            
        }
        return ans;
    }
};