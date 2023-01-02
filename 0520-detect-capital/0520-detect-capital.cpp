class Solution {
public:
    bool detectCapitalUse(string word) 
    {
      char ch1=word[0];
      char ch2;
      if(word.length()>1)
      {
        ch2=word[1];
      }
      bool both=false;
      if(isupper(ch1) and isupper(ch2))
      {
        for(int i=2;i<word.size();i++)
        {
          if(islower(word[i]))
          {
            return false;
          }
        }
      }
      else if(isupper(ch1))
      {
        for(int i=1;i<word.size();i++)
        {
          if(isupper(word[i]))
          {
            return false;
          }
        }
      }
      else
      {
        for(int i=1;i<word.size();i++)
        {
          if(isupper(word[i]))
          {
            return false;
          }
        }
      }
      return true;
      
    }
};