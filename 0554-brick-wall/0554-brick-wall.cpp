class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        // initialing to store no of empty spaces between bricks
        map<int,int>mp;    
        
        // total width of bricks
        int widht = accumulate(wall[0].begin(),wall[0].end(),0);
        
        for(auto it : wall)
        {
            int prev = 0;
            for(auto jt : it)
            {
                if(prev+jt!=widht)
                {
                    mp[prev+jt]++;
                    prev = prev + jt;
                }
            }
        }
         
        int max_space = 0;
        for(auto it  : mp)
        {
            max_space = max(max_space,it.second);
        }
        
        // here wall.size() - max_space represent that , we remove no . white space occupied in the column
        return wall.size() - max_space;
        
    }
};