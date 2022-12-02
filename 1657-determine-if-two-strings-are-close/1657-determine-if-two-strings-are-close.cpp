class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        int s1 = word1.size();
        int s2 = word2.size();
        
        if(s1!=s2)
        {
            return false;
        }
        
        vector<int>vec1(26,0),vec2(26,0),mp1(26,0),mp2(26,0);
        
        for(auto it:word1)
        {
            mp1[it-'a']++;
            vec1[it-'a']=1;
        }
        
        for(auto it:word2)
        {
            mp2[it-'a']++;
            vec2[it-'a']=1;
        }
        
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        return vec1==vec2&&mp1==mp2;
    }
};