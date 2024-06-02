class Solution {
public:
     bool row[9][10], col[9][10], sq[9][10];

    bool isValid(int i, int j, int num) {
        int k = (i / 3) * 3 + (j / 3);
        return !row[i][num] && !col[j][num] && !sq[k][num];
    }

    void visit(int i, int j, int num) {
        int k = (i / 3) * 3 + (j / 3);
        row[i][num] = col[j][num] = sq[k][num] = true;
    }

    void unvisit(int i, int j, int num) {
        int k = (i / 3) * 3 + (j / 3);
        row[i][num] = col[j][num] = sq[k][num] = false;
    }

    bool Backtrack(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return Backtrack(board, i + 1, 0);
        if (board[i][j] != '.') return Backtrack(board, i, j + 1);

        for (int num = 1; num <= 9; num++) {
            if (isValid(i, j, num)) {
                board[i][j] = num + '0';
                visit(i, j, num);
                if (Backtrack(board, i, j + 1)) return true;
                board[i][j] = '.';
                unvisit(i, j, num);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(sq, false, sizeof(sq));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    visit(i, j, num);
                }
            }
        }
        Backtrack(board, 0, 0);
    }
};