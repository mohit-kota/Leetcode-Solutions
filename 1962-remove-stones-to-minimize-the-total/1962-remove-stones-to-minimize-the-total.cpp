class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int,vector<int>>pq;
        int n = piles.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            
            pq.push(piles[i]);
            sum+=piles[i];
        }
        
        while(k>0)
        {
            int val = pq.top();
            pq.pop();
            pq.push((val+1)/2);
            k--;
            sum-=(val)/2;
        }
        
        // while(!pq.empty())
        // {
        //     sum = sum + pq.top();
        //     pq.pop();
        // }
        return sum;
        
    }
};