class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        multiset<int>st;
        int n = nums.size();
        int i = 0;
        long long ans = 0;
        int j = 0;
        while(i<n)
        {
            while(j<n && (st.size()==0 or (max(nums[j],*(st.rbegin()))-min(nums[j],*(st.begin())))<=2 ) )
            {
                st.insert(nums[j]);
                j = j+1;
            }
            
            
            ans = ans + st.size();
            st.erase(st.find(nums[i]));
            i = i+1;
        }
        return ans;
        
    }
};