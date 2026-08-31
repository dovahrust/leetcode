typedef ptrdiff_t isize;

constexpr char INVALID_CHAR = '#';

struct Node {
    isize childs[26];
    bool is_end;
    bool is_deleted;

    Node() {
       for (auto& c : childs) { c = -1; }
       is_end = false;
       is_deleted = false;
    }
};

struct Trie {
    vector<Node> arr;
    Trie(){}

    inline static void init_freqs_board(span<size_t> freqs, const vector<vector<char>>& board) {
        for (auto& r : board) {
            for (const unsigned char c : r) {
                assert(c >= 'a' && c <= 'z');
                freqs[c - 'a'] += 1;
            }
        }
    }

   inline static void init_adj_board(span<size_t> adj, const vector<vector<char>>& board) {
        const size_t rows = board.size();
        const size_t cols = board[0].size();
        for (size_t i = 0; i < rows; i += 1) {
            for (size_t j = 0; j < cols; j += 1) {
                const size_t curr = static_cast<size_t>(board[i][j] - 'a');
                if (i > 0) {
                    const size_t up = static_cast<size_t>(board[i - 1][j] - 'a');
                    adj[up * 26 + curr] += 1;
                    if (up != curr) { adj[curr * 26 + up] += 1; }
                }

                if (j > 0) {
                    const size_t le = static_cast<size_t>(board[i][j - 1] - 'a');
                    adj[le * 26 + curr] += 1;
                    if (le != curr) { adj[curr * 26 + le] += 1; }
                }
            }
        }
    }

    static Trie from_string_slices(const vector<string>& words, const vector<vector<char>>& board) {
        size_t freqs_board[26] = { 0 };
        init_freqs_board(freqs_board, board);
        size_t adj_board [26 * 26] = { 0 };
        init_adj_board(adj_board, board);

        auto arr = vector<Node>();
        arr.push_back(Node());
        for (const string& word : words) {
            bool is_valid = true;
            size_t freqs_word[26] = { 0 };
            for (const unsigned char ch : word) {
                assert(ch >= 'a' && ch <= 'z');
                freqs_word[ch - 'a'] += 1;
                if (freqs_word[ch - 'a'] > freqs_board[ch - 'a']) {
                    is_valid = false;
                    break;
                }
            }
            if (!is_valid) { continue; }

            size_t adj_word[26 * 26] = { 0 };
            const size_t word_len = word.size();
            for (size_t i = 1; i < word_len; i += 1) {
                const size_t a = static_cast<size_t>(word[i] - 'a');
                const size_t b = static_cast<size_t>(word[i - 1] - 'a');
                adj_word[a * 26 + b] += 1;
                if (a != b) {
                    adj_word[b * 26 + a] += 1;
                }
                if (adj_word[a * 26 + b] > adj_board[a * 26 + b]) {
                    is_valid = false;
                    break;
                }
            }
            if (!is_valid) { continue; }

            size_t curr = 0;
            for (const unsigned char ch : word) {
                const size_t child_idx  = static_cast<size_t>(ch - 'a');
                if (arr[curr].childs[child_idx] == -1) {
                    arr[curr].childs[child_idx] = std::ssize(arr);
                    arr.push_back(Node());
                }
                curr = static_cast<size_t>(arr[curr].childs[child_idx]);
            }
            arr[curr].is_end = true;
        }

        auto res = Trie();
        res.arr = arr;
        return res;
    }

    inline bool mark_node_deleted_if_possible(const size_t node_idx) {
        if (arr[node_idx].is_end) { return false; }

        for (const auto& c : arr[node_idx].childs) {
            if (c != -1 && !arr[c].is_deleted) {
                return false;
            }
        }

        arr[node_idx].is_deleted = true;
        return true;
    }

    void dfs(
        const size_t trie_idx,
        vector<vector<char>>& board,
        const isize rows,
        const isize cols,
        const isize i,
        const isize j,
        string& tmp,
        vector<string>& res
    ) {
        if (arr[trie_idx].is_deleted) { return; }

        if (arr[trie_idx].is_end) {
            arr[trie_idx].is_end = false;
            res.push_back(tmp);
            if (mark_node_deleted_if_possible(trie_idx)) { return; }
        }

        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] == INVALID_CHAR) {
            return;
        }

        const char orig = board[i][j];
        const isize new_trie_idx_isize = arr[trie_idx].childs[static_cast<unsigned char>(orig - 'a')];
        if (new_trie_idx_isize == -1) {
            return;
        }

        const size_t new_trie_idx = static_cast<size_t>(new_trie_idx_isize);
        board[i][j] = INVALID_CHAR;
        tmp.push_back(orig);

        dfs(new_trie_idx, board, rows, cols, i + 1, j, tmp, res);
        dfs(new_trie_idx, board, rows, cols, i - 1, j, tmp, res);
        dfs(new_trie_idx, board, rows, cols, i, j + 1, tmp, res);
        dfs(new_trie_idx, board, rows, cols, i, j - 1, tmp, res);
        mark_node_deleted_if_possible(new_trie_idx);

        tmp.pop_back();
        board[i][j] = orig;
    }

    inline static vector<string> run(vector<vector<char>>& board, const vector<string>& words) {
        const isize rows = std::ssize(board);
        const isize cols = std::ssize(board[0]);
        auto trie = from_string_slices(words, board);
        auto tmp = string();
        auto res = vector<string>();

        for (isize i = 0; i < rows; i += 1) {
            for (isize j = 0; j < cols; j += 1) {
                trie.dfs(0, board, rows, cols, i, j, tmp, res);
                if (trie.mark_node_deleted_if_possible(0)) { return res; }
            }
        }

        return res;
    }
};

class Solution {
public:
    static vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        return Trie::run(board, words);
    }
};
