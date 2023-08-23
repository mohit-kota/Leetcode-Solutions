class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string newstr = "";
        
        int n1 = word1.size();
        int n2 = word2.size();
        int i=0 , j = 0;
        
        bool flag = true; // next one 
        
        while(i<n1 or j<n2)
        {
            if(i<n1 and flag)
            {
                newstr+=word1[i];
                flag = false;
                i=i+1;
            }
            else{
                flag = false;
            }
            
            if(j<n2 and !flag)
            {
                newstr+=word2[j];
                j++;
                flag = true;
            }
            else{
                flag = true;
            }
        }
        return newstr;
        
    }
};