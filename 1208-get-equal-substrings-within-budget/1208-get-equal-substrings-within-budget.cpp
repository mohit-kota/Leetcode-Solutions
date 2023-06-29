class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int size = s.size();
        int count= 0;
        int maxlen = INT_MIN;
        
        int i = 0;
        int j = 0;
        while(i<size)
        {
            int assci_cost = s[i] - t[i];
            assci_cost = abs(assci_cost);
            // cout<<assci_cost<<endl;
            if(count+assci_cost<=maxCost)
            {
                count = count + assci_cost;
                maxlen = max(maxlen,i-j+1);
                i = i + 1;
            }
            else
            {
                count = count + assci_cost;
                while(count>maxCost)
                {
                    int assci_cost = s[j] - t[j];
                    assci_cost = abs(assci_cost);
                    count = count - assci_cost;
                    j = j + 1;
                }
                
                maxlen = max(maxlen,i-j+1);
                i = i + 1;
            }
        }
        return maxlen==INT_MIN?0:maxlen;
        
    }
};