class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        map<int,bool>mt;
        vector<int>uniq;
        for(auto it : nums)
        {
            if(!mt[it])
            {
                uniq.push_back(it);
                mt[it] = true;
            }
            
        }
        
        // cout<<uniq.size()<<endl;
        int n = nums.size();
        int answer = 0;
//         for(int i=0;i<n;i++)
//         {
//             set<int>st;
//             for(int j=i;j<n;j++)
//             {
//                 st.insert(nums[j]);
                
//                 if(st.size() == uniq.size())
//                 {
//                     answer = answer + 1;
//                 }
//             }
//         }
        
        int left = 0;
        int right = 0;
        
        map<int,int>mp;
        while(right<n)
        {
            mp[nums[right]]++;
            while(mp.size()==uniq.size())
            {
                answer += n - right;
                
                mp[nums[left]]--;
                
                if(mp[nums[left]]==0)
                {
                    mp.erase(nums[left]);
                }
                left++;
                
            }
            right++;
        }
        
        return answer;
    }
};