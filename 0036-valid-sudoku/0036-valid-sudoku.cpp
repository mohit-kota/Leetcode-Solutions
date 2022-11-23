class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        map<char,bool>row;
        map<char,bool>col;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                // rows
                if(row[board[i][j]]==true)
                {
                    return false;
                }
                if(board[i][j]!='.')
                {
                    row[board[i][j]]=true;
                }
                // columns
                if(col[board[j][i]]==true)
                {
                    return false;
                }
                if(board[j][i]!='.')
                {
                    col[board[j][i]]=true;
                }
                
            }
            row.clear();
            col.clear();
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                map<char,bool>box;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(box[board[k][l]]==true)
                        {
                            return false;
                        }
                        if(board[k][l]!='.')
                        {
                            box[board[k][l]]=true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
    
};