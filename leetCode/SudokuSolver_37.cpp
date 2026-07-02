class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch)
                return false;

            if (board[i][col] == ch)
                return false;

            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if (board[r][c] == ch)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    for (char ch = '1'; ch <= '9'; ch++) {

                        if (isValid(board, i, j, ch)) {

                            board[i][j] = ch;

                            if (solve(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// optimized 

class Solution {
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    int b = (i / 3) * 3 + (j / 3);

                    for (int num = 1; num <= 9; num++) {

                        if (!row[i][num] && !col[j][num] && !box[b][num]) {

                            board[i][j] = num + '0';
                            row[i][num] = col[j][num] = box[b][num] = true;

                            if (solve(board))
                                return true;

                            board[i][j] = '.';
                            row[i][num] = col[j][num] = box[b][num] = false;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int b = (i / 3) * 3 + (j / 3);

                    row[i][num] = true;
                    col[j][num] = true;
                    box[b][num] = true;
                }
            }
        }

        solve(board);
    }
};
