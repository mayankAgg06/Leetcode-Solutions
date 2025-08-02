class Solution {
public:
    bool isValid(vector<vector<char>>& board, int icurr, int jcurr)
    {
        int row = icurr/3;
        row*=3;
        int col = jcurr/3;
        col*=3;
        for(int i=row; i<row+3; i++)
        {
            for(int j=col; j<col+3; j++)
            {
                if(i!=icurr and j!=jcurr and board[i][j]==board[icurr][jcurr])return false;
            }
        }
        for(int i=0; i<9; i++)
        {
            if(i!=jcurr and board[icurr][i]==board[icurr][jcurr]) return false;

            if(i!=icurr and board[i][jcurr]==board[icurr][jcurr]) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.' and !isValid(board,i,j))return false;
            }
        }

        return true;
        
    }
};