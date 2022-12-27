class Solution {
public:
   static bool  cmp(pair<int,int> &a,pair<int,int> &b){
            return a.first < b.first;
        }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        // sort  based on capacity 
        // and fill 
        
        vector<int>vec;
        
        int n = capacity.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back(capacity[i]-rocks[i]);
        }
        
        sort(vec.begin(),vec.end());
        
        int count = 0;
        
     
        for(int i=0;i<n;i++)
        {
            if(additionalRocks-vec[i]>=0)
            {
                additionalRocks-=vec[i];
                count++;
            }
            else {
                break;
            }
        }
            
        return count;
    }
};