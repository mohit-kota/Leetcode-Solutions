class Solution {
public:
    string reverseVowels(string s) 
    {
        map<char , bool>mp;
        mp['a'] = true;
        mp['A'] = true;
        mp['e'] = true;
        mp['E'] = true;
        mp['i'] = true;
        mp['I'] = true;
        mp['o'] = true;
        mp['O'] = true;
        mp['u'] = true;
        mp['U'] = true;
        
        int i = 0, j = s.size()-1;
        
        while(i<j)
        {
            while(i<s.size() and !mp[s[i]])
            {
                i++;
            }
            
            while(j>=0 and !mp[s[j]])
            {
                j--;
            }
            
            if(i<j)
            {
                swap(s[i++],s[j--]);
            }
        }
        return s;
    }
};