class Solution {
public:
    bool isSafe(int row, int col, char c, vector<vector<char>>& board) {
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == c)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == c)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int n) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isSafe(row, col, c, board)) {
                            board[row][col] = c;

                            if (solve(board, n))
                                return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board, n);
    }
};