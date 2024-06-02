class Solution {
public:
    bool safeToPlace(vector<vector<char>>& board, int i, int j, int n,
                     int num) {
        for (int k = 1; k <= n; k++) {
            if (board[i][k - 1] == num + '0' || board[k - 1][j] == num + '0') {
                return false;
            }
        }
        n = sqrt(n);
        int si = (i / n) * n;
        int sj = (j / n) * n;

        for (int a = si; a < si + n; a++) {
            for (int b = sj; b < sj + n; b++) {
                if (board[a][b] == num + '0') {
                    return false;
                }
            }
        }
        return true;
    }

    bool solving(vector<vector<char>>& board, int i, int j, int n) {
        if (i == n)
            return true;

        if (j == n) {
            return solving(board, i + 1, 0, n);
        }

        if (board[i][j] != '.')
            return solving(board, i, j + 1, n);

        for (int val = 1; val <= 9; val++) {

            if (safeToPlace(board, i, j, n, val) == true) {
                board[i][j] = val+'0';
                bool kyaBakihua = solving(board, i, j + 1, n);
                if (kyaBakihua == true) {
                    return true;
                }
                board[i][j] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solving(board, 0, 0, board.size());
    }
};