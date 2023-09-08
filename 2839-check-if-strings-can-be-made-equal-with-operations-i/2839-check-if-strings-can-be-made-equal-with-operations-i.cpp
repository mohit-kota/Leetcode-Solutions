class Solution {
public:
    bool canBeEqual(string s1, string s2) 
    {
        int len = s1.size();
        for(int i=0;i<len;i++)
        {
            if(i<len/2)
            {
               if( s1[i]!=s2[i]  && s1[i]!=s2[i+2])
               {
                   return false;
               }
            }
            else{
                if(s1[i]!=s2[i]  &&  s1[i]!=s2[i-2])
                {
                    return false;
                }
            }
        }
        return true;
    }
};