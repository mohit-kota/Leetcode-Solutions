class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        sort(piles.begin(),piles.end());
        int low  = 1;
        int high = *max_element(piles.begin(),piles.end());
        
        while(low<high)
        {
            int mid = (low+high)/2;
            
            int hourspent=0;
            
            for(auto i:piles)
            {
                // here we have pile element by k 
                // if k has reminder greater than 0 add 1 else no 
                hourspent += (i/mid);
                if(i%mid!=0)
                {
                    hourspent++;
                }
            }
            
            if(hourspent<=h)
            {
                high=mid;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return high ;
    }
};