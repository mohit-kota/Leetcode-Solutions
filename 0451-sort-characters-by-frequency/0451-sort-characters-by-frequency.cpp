class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int>mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        
        
        priority_queue< pair<int,char> , vector<pair<int,char>> > pq;
        
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        
        string ans = "";
        
        while(!pq.empty())
        {
            auto val = pq.top();
            pq.pop();
            char ch = val.second;
            int cnt = val.first;
            
            for(int i=0;i<cnt;i++)
            {
                ans+=ch;
            }
        }
        
        return ans;
    }
};