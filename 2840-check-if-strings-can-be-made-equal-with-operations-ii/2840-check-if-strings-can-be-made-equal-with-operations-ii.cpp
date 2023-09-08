class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int len = s1.size();
        unordered_map<char,int>mp1_od , mp1_eve;
        unordered_map<char,int>mp2_eve , mp2_od;
        for(int i=0;i<len;i++)
        {
            if(i%2==0)
            {
                mp1_eve[s1[i]]++;
                mp2_eve[s2[i]]++;
                // cout<<"even "<<s1[i]<<" "<<mp1_eve[s1[i]]<<" "<<s2[i]<<" "<<mp2_eve[s2[i]]<<endl;
            }
            else{
                mp1_od[s1[i]]++;
                mp2_od[s2[i]]++;
                
                // cout<<"odd "<<s1[i]<<" "<<mp1_od[s1[i]]<<" "<<s2[i]<<" "<<mp2_od[s2[i]]<<endl;
            }
        }
        return (mp1_eve == mp2_eve && mp1_od == mp2_od);
    }
};