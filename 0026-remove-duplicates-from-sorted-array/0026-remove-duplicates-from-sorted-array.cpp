class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        set<int>uniq;
        for(int i=0;i<nums.size();i++)
        {
            uniq.insert(nums[i]);
        }
        int length=uniq.size();
        int i=0;
        for(auto x:uniq)
        {
            nums[i]=x;
            i++;
        }
        return length;
        
    }
};