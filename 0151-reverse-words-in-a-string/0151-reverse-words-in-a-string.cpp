class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        int n = s.length();
        string str = "";
        string ans = "";
        for(int i=0;i<n;){
            if(s[i] == ' '){
                while(s[i] == ' ' && i<n){
                    if(str.length())
                    vec.push_back(str);
                    str = "";
                    i++;
                }
            }else{
                str+=s[i];
                i++;
            }
        }
        if(str.length()){
            vec.push_back(str);
        }
        
        // for(int i=vec.size()-1;i>=0;i--){
        //     cout<<vec[i]<<" ";
        // }
        // cout<<endl;
        
        for(int i=vec.size()-1;i>=0;i--){
            if(vec[i]!=" ")
            ans=ans+vec[i];
            if(i!=0 && i!=n-1)
                ans+=" ";
        }
        return ans;
    }
};