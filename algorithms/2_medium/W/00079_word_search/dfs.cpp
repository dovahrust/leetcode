typedef ptrdiff_t isize;

constexpr char INVALID_CHAR = '#';

class Solution {
    static bool dfs(
        vector<vector<char>>& board, const isize rows, const isize cols,
        const isize i, const isize j,
        const string& word, const isize word_len, const isize word_idx
    ) {
        if (word_len == word_idx) {
            return true;
        }

        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[word_idx]) {
            return false;
        }

        const char orig = board[i][j];
        board[i][j] = INVALID_CHAR;

        const bool res = dfs(board, rows, cols, i + 1, j, word, word_len, word_idx + 1) ||
                         dfs(board, rows, cols, i - 1, j, word, word_len, word_idx + 1) ||
                         dfs(board, rows, cols, i, j + 1, word, word_len, word_idx + 1) ||
                         dfs(board, rows, cols, i, j - 1, word, word_len, word_idx + 1);

        board[i][j] = orig;

        return res;
    }
public:
    static bool exist(vector<vector<char>>& board, const string word) {
        const isize rows = std::ssize(board);
        const isize cols = std::ssize(board[0]);
        const isize word_len = std::ssize(word);

        for (isize i = 0; i < rows; i += 1) {
            for (isize j = 0; j < cols; j += 1) {
                if (dfs(board, rows, cols, i, j, word, word_len, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
