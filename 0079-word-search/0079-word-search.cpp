class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int n)
    {
        // if the n comes to word.size()
        // that means we found the word in board 
        if(n==word.size())
        {
            return true;
        }
        // boundary cases , if out of range of boundary return false;
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!=word[n])
        {
            return false;
        }
        // we are storing that character for reverting the changes what we do 
        char temp = board[i][j];
        // we visited the one character 
        board[i][j]='0';
        
        bool res = (dfs(board,word,i+1,j,n+1) || 
                    dfs(board,word,i-1,j,n+1) || 
                    dfs(board,word,i,j+1,n+1) || 
                    dfs(board,word,i,j-1,n+1));
        board[i][j]=temp;
        
        return res;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        if(word=="")
        {
            return false;
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0] and dfs(board,word,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};