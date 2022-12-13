class Solution {
public:
    int findans(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&vec)
    {
        if(i==mat.size()-1 and j>=0 and j<mat[0].size())
        {
            return mat[i][j];
        }
        
        if(j<0 or j>=mat[0].size())
        {
            return INT_MAX;
        }
        
        if(vec[i][j]!=INT_MAX)
        {
            return vec[i][j];
        }
        
        return vec[i][j]=mat[i][j]+min(min(findans(i+1,j-1,mat,vec),findans(i+1,j,mat,vec)),findans(i+1,j+1,mat,vec));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int mini=INT_MAX;
        int row = matrix.size();
        int col = matrix[0].size();
        int sum = 0;
        vector<vector<int>>vec(row+1,vector<int>(col+1,INT_MAX));
        for(int i=0;i<col;i++)
        {
            int val = findans(0,i,matrix,vec);
            mini = min(mini,val);
        }
        
        return mini;
    }
};