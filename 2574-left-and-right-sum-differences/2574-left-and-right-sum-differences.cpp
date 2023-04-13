class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) 
    {
        int len = nums.size();
        if(len<2)
        {
            return {0};
        }
        
        vector<int>leftsum(len,0) , rightsum(len,0),answer;
        
        for(int i=1;i<len;i++)
        {
            leftsum[i]=leftsum[i-1]+nums[i-1];
            // cout<<leftsum[i]<<endl;
            
            rightsum[len-i-1] = rightsum[len-i]+nums[len-i];
            // cout<<rightsum[len-i]<<endl;
        }
        for(int i=0;i<len;i++)
        {
            answer.push_back(abs(leftsum[i]-rightsum[i]));
        }
        
        return answer;
    }
};