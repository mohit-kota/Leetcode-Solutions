class Solution {
public:
    void moveZeroes(vector<int>& s) 
    {
        int i=0,j=0,n=s.size();
        while(i<n)
        {
            if(s[i]!=0)
            {
                swap(s[i],s[j]);
                i++;j++;
            }
            else
            {
                i++;
            }
        }
        
    }
};