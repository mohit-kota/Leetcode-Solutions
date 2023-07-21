class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int maxe = *max_element(nums.begin(),nums.end())+k;
        // int mini = *min_element(nums.begin(),nums.end(),)
        vector<int>diffarray(maxe+2,0);
        
        
        vector<int>prefix;
        for(auto it : nums)
        {
            int minr = (it-k)>=0?(it-k):0;
            int maxr = it+k;
            
            diffarray[minr] += 1;
            diffarray[maxr+1] -= 1;
        }
        int maxelement=INT_MIN;
        for(int i=0;i<diffarray.size()-1;i++)
        {
            if(prefix.size()>0)
            {
                int x = prefix.back();
                int c = x + diffarray[i];
                maxelement = max(c,maxelement);
                prefix.push_back(c);
            }
            else{
                prefix.push_back(diffarray[i]);
                maxelement = max(diffarray[i],maxelement);
            }
            
        }
        return maxelement;
        
        
        
       
    }
};