class Solution {
public:
    
    int isvowel(char ch)
    {
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
    
    int start_tail_vowel(string s)
    {
        
        return isvowel(s[0]) && isvowel(s[s.size()-1]);
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        vector<int>ans;
        int words_size = words.size();
        vector<int>prefix(words_size,0);
        prefix[0] = start_tail_vowel(words[0]);
        // cout<<prefix[0]<<endl;
        for(int i=1;i<words_size;i++)
        {
            if(start_tail_vowel(words[i]))
            {
                prefix[i] = prefix[i-1] + 1;
            }
            else{
                prefix[i] = prefix[i-1] + 0;
            }
            // cout<<prefix[i]<<endl;
        }
        
        for(auto it : queries)
        {
            int l = it[0];
            int r = it[1];
            if(l==0)
            {
                ans.push_back(prefix[r]);
            }
            else{
                ans.push_back(prefix[r]- prefix[l-1]);
            }
        }
        return ans;
    }
};