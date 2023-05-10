class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) 
    {
        vector<int>color(n,0);
        int maxcnt = 0;
        vector<int>ans;
        int j= 0;
        for(auto it:queries)
        {
            
            if(color[it[0]] && it[0]-1>=0 && color[it[0]-1]==color[it[0]]) maxcnt--;
            if(color[it[0]] && it[0]+1<n && color[it[0]+1]==color[it[0]]) maxcnt--;
            color[it[0]] = it[1];            
            if(color[it[0]] && it[0]-1>=0 && color[it[0]-1]==color[it[0]]) maxcnt++;
            if(color[it[0]] && it[0]+1<n && color[it[0]+1]==color[it[0]]) maxcnt++;
            
            
            ans.push_back(maxcnt);
            // break;
        }
        return ans;
    }
};

