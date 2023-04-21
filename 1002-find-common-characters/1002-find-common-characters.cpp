class Solution {
public:
    
    vector<string> commonChars(vector<string>& words) 
    {
        vector<string>answer;
        
        map<char,int>mp;
        for(auto it : words[0])
        {
            mp[it]++;
        }
        string word = words[0];
        map<char,int>zp;
        for(auto it : word)
        {
            int flag = 1;
            if(zp[it])
            {
                continue;
            }
            zp[it]=1;
            for(int i=1;i<words.size();i++)
            {
                string word = words[i];
                map<char,int>tp;
                for(auto it : word){
                    tp[it]++;
                }
                if(mp[it]!=0)
                {
                    
                    mp[it] = min(mp[it],tp[it]);
                    // flag = 0;     
                }
                else{
                    flag = 0;
                }
            }   
            if(flag){
                
                for(int j=0;j<mp[it];j++)
                {
                    string val = "";
                    val+=it;
                    answer.push_back(val);
                }
                    
                // answer.push_back(val);
            }
        }
        return answer;
        
        
        
    }
};