class Solution {
public:
    // static bool cmp(vector<int>&a,vector<int>&b)
    // {
    //     if(a[1]==b[1])
    //     {
    //         return a[0]<b[0];
    //     }
    //     return a[1]<b[1];
    // }
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size()==0)
        {
            return 0;
        }
       sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]==b[1])return a[0]<b[0];
            return a[1]<b[1];
        });
        
        
        int count = 1;
        int pre = points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(pre>=points[i][0]) // if the pre ballon end is greter than current first 
                // then it means that current will also burst if the pre bursts 
            {
                continue;
            }
            count++;
            pre = points[i][1];
        }
        return count;
    }
};