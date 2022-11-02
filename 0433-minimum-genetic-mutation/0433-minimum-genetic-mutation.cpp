class Solution {
public:
    int bfs(string start,string end,vector<string>&bank)
    {
        
        queue<string>q;
        q.push(start);
        map<string,bool>mp;
        
        int n = start.size();
        int steps = 0;
        while(!q.empty())
        {
            int size =  q.size();
            for(int i=0;i<size;i++)
            {
                string s = q.front();
                q.pop();
                
                if(s == end)
                {
                    return steps;
                }
                
                for(auto c : "ACGT")
                {
                    for(int j=0;j<n;j++)
                    {
                        string neibhour = s;
                        neibhour[j] = c;
                        if(!mp[neibhour] and find(bank.begin(),bank.end(),neibhour)!=bank.end())
                        {
                            mp[neibhour] = true;
                            q.push(neibhour);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    int minMutation(string start, string end, vector<string>& bank)
    {
        return bfs(start,end,bank);    
    }
};