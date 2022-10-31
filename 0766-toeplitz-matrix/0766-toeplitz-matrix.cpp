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
                int r = i;
                int c = j;
                int val = matrix[r][c];
                while(r<row and c<col)
                {
                    if(matrix[r][c]!=val)
                    {
                        return false;
                    }
                    r++;
                    c++;
                }
            }
        }
        return true;
    }
};