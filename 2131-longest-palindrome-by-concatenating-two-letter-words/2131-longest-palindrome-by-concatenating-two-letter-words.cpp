class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int n = words.size();
        map<string,int>mp;
        for(auto it : words)
        {
            mp[it]++;
        }
        int count = 0;
        //                                       |
        //                                       v
        // for center check like cl lc gg --- clgglc
        bool flag = false;
        
        for(auto it : words)
        {
            string x = it;
            reverse(x.begin(),x.end());
            string w = it;
            
            if(w!=x and mp[w]>0 and mp[x]>0)
            {
                count+=4;
                mp[w]--;
                mp[x]--;
            }
            // for string aa aa , occurs 2 times , cl aa aa lc
            else if(w==x and mp[w]>1)
            {
                mp[w]-=2;
                count+=4;
            }
            else if(w==x and !flag and mp[w]>0)
            {
                mp[w]--;
                count+=2;
                flag = true;
            }
        }
        
        return count;
        
    }
};