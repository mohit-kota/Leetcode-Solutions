class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i>0 and j>0 and matrix[i-1][j-1]!=matrix[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};