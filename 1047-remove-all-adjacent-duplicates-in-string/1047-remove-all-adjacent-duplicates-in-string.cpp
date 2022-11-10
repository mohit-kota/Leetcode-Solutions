class Solution {
public:
    string removeDuplicates(string str) 
    {
        stack<char>s;
        for(auto x:str)
        {
            if(!s.empty())
            {
                if(x==s.top())
                {
                    s.pop();
                }
                else
                {
                    s.push(x);
                }
            }
            else
            {
                s.push(x);
            }
        }
        string ans="";
       while(!s.empty())
       {
           ans+=s.top();
           s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};