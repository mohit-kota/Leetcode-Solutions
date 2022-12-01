class Solution {
public:
    bool isvowel(char ch)
    {
        return ch=='a' or ch=='A' or ch=='e' or ch=='E' or ch=='i' or ch=='I' or ch=='o' or ch=='O' or ch=='u' or ch=='U';
    }
    
    bool halvesAreAlike(string s) 
    {
        int len = s.size();
        int first_half = 0;
        int secnd_half = 0;
        
        
        for(int i=0;i<len;i++)
        {
            if(i<len/2)
            {
                first_half += isvowel(s[i]);
            }
            else
            {
                secnd_half += isvowel(s[i]);
            }
        }
        
        return first_half == secnd_half;
    }
};