class Solution {
public:
    string makeGood(string s) 
    {
        string ans = "";
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(!st.empty())
            {
                char top = st.top();
                char cur = s[i];
                // cout<<top<<" "<<cur<<endl;
                if(isupper(top) and islower(cur))
                {
                    // same carracter 
                    // cout<<top<<" 1 "<<ccur+32<<endl;
                    if(cur-32 == top)
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(cur);
                    }
                }
                else if(islower(top) and isupper(cur))
                {
                    if(top-32 == cur)
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(cur);
                    }   
                }
                else{
                    st.push(cur);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};