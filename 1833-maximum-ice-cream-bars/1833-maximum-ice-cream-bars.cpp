class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());
        int count = 0;
        if(costs[0]>coins)
        {
            return 0;
        }
        else{
            count+=1;
            coins-=costs[0];
            for(int i=1;i<costs.size();i++)
            {
                if(costs[i]<=coins)
                {
                    coins-=costs[i];
                    count++;
                }
                else
                {
                    break;
                }
                
            }
        }
        return count;
    }
};