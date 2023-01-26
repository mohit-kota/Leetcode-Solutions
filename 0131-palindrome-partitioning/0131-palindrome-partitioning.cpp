class Solution {
public:
    // this is to check whether the string of length start to end is 
    // palindrone or not 
    bool ispalin(string s,int start,int end)
    {
        int i=start;
        int j=end;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // solve() func will be the main func
    void solve(vector<vector<string>>&all,vector<string>&curr,int start,int n ,string s)
    {
        // base case 
        if(start>=n)
        {
            all.push_back(curr);
            return ;
        }
        // check for all the
        for(int i=start;i<n;i++)
        {
            // check if the current length of substring is palindrone or not 
            if(ispalin(s,start,i))
            { 
                // cout<<start<<"  "<<i<<endl;
                // cout<<"s :"<<s.substr(start,i-start+1)<<endl;
                curr.push_back(s.substr(start,i-start+1)); // using that substring
                solve(all,curr,i+1,n,s);
                curr.pop_back(); // revoking all the changes back 
            }
        }
    }
   
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>all;
        vector<string>curr;
        solve(all,curr,0,s.size(),s);
        return all;
    }
};