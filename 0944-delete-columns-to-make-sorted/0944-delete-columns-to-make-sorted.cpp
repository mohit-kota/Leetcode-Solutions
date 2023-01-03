class Solution {
public:
    bool deleteit(int i,vector<string>strs)
    {
        char prev = strs[0][i];
        for(int j=1;j<strs.size();j++)
        {
            if(prev>strs[j][i])
            {
                return true;
            }
            else
            {
                prev = strs[j][i];
            }
        }
        return false;
    }
    int minDeletionSize(vector<string>& strs) 
    {
        int n = strs[0].size(); // string size 
        int del = 0;
        // traverse on each col
        for(int i=0;i<n;i++)
        {
            if(deleteit(i,strs))
            {
                del++;
            }
        }
        return del;
    }
};