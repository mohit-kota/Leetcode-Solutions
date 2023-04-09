class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int firstzero = -1;
        int answer = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if(firstzero==-1)
                {
                    answer = max(answer , i);
                    firstzero = i;
                }
                else{
                    answer = max(answer , i-firstzero-1);
                    firstzero = i;
                }
            }
        }
        int len = nums.size()-firstzero-1;
     
        answer = max(answer,len);
        return answer;
    }
};