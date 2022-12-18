class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        int n=temp.size();
        vector<int>ans(temp.size());
        stack<int>s;
        s.push(0);
        int i=1;
        while(!s.empty()&&i<n)
        {
            while(!s.empty()&&i<n&&temp[i]>temp[s.top()])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
            i++;
            
        }
        return ans;
        
        
    }
};