class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        int arr_size = arr.size();
        
//         map<int,pair<int,int>>mp;
//         map<int,int>row , col ;
//         // each value points to its index in 2d array
//         for(int i=0;i<m;i++)
//         {   row[i] = 0;
//             for(int j=0;j<n;j++)
//             {
//                 col[j] = 0; 
//                 mp[mat[i][j]] = {i,j};
//             }
//         }
        
//         for(int i=0;i<arr_size;i++)
//         {
//             auto indexs = mp[arr[i]];
            
//             // paint in mat
//             mat[indexs.first][indexs.second] = -1;
//             row[indexs.first] += 1;
//             col[indexs.second] += 1;
//             if(row[indexs.first]==n  or col[indexs.second]==m)
//             {
//                 return i;
//             }
//         }
        
        map<int,int>mp;
        for(int i=0;i<arr_size;i++)
        {
            mp[arr[i]] = i;
        }
        
        int ans = INT_MAX;
        for(int i=0;i<m;i++)
        {
            int c = 0;
            for(int j=0;j<n;j++)
            {
                c = max(c,mp[mat[i][j]]);
            }
            ans = min(ans,c);
        }
        
        for(int i=0;i<n;i++)
        {
            int c = 0;
            for(int j=0;j<m;j++)
            {
                c = max(c,mp[mat[j][i]]);
            }
            ans = min(ans,c);
        }
        
        return ans;
        
        
        
    }
};