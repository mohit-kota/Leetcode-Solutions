class Solution {
public:
    int countWays(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int answer = 0;
        int selected =0;
        if(nums[0]!=0)
        {
            answer = 1; // not selecting any one 
        }
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            selected++;
            if(selected>nums[i])
            {
                if(i+1<n && selected<nums[i+1]){
                    answer=answer+1;
                }
                else if(i+1==n)
                {
                    answer++;
                }
            }
        }
        return answer;
    }
};