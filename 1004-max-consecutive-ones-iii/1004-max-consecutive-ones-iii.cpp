class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
       
        int answer = 0;
        int len = nums.size();
        int temp = k; // storing the value of k temporarily 
        int i = 0;
        int loc = 0;
        for(int j=0;j<len;j++)
        {
            // cout<<"iteration "<<j<<endl;
            if(nums[j]==1)
            {
                loc=j;
            }
            else{
                if(temp>0)
                {
                    loc = j;
                    temp--;
                }
                else{
                    while(i<len)
                    {
                        if(nums[i]==0)
                        {
                            // temp++;
                            break;
                        }
                        i++;
                    }
                    loc = j;
                    
                    i+=1;
                }
                
            }
            // cout<<"i is"<<i<<" loc is "<<loc<<endl;
                answer = max(answer , loc-i+1);
        }
        return answer;
    }
};