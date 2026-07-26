typedef ptrdiff_t isize;

class Solution {
    static auto make_board_flat(const vector<vector<int>>& board) -> vector<int> {
        const isize n = std::ssize(board);
        auto flat_board = vector<int>();
        flat_board.reserve((n * n) + 1);
        flat_board.push_back(-2); // cell 0 doesnt exist;
        bool flip_flop = true;
        for (isize i = n - 1; i >= 0; i -= 1) {
            const auto& b = board[i];

            if (flip_flop) {
                for (const int val : b) {
                    flat_board.push_back(val);
                }
            } else {
                for (auto it = b.crbegin(); it != b.crend(); it += 1) {
                    flat_board.push_back(*it);
                }
            }
            flip_flop = !flip_flop;
        }
        assert(flat_board[1] == -1 && flat_board[n * n] == -1);

        return flat_board;
    }

public:
    static int snakesAndLadders(const vector<vector<int>>& board) {
        const isize n = std::ssize(board);
        assert(n >= 2 && n <= 20 && std::ssize(board[0]) == n);
        const auto flat_board = make_board_flat(board);

        const int target = static_cast<int>(n * n);
        auto q = queue<int>();
        q.push(1);
        auto seen = vector<char>((n * n) + 1, 0);
        seen[1] = 1;
        int rolls = 1;

        while (!q.empty()) {
            const isize q_len = std::ssize(q);

            for (isize _cnt = 0; _cnt < q_len; _cnt += 1) {
                const int node = q.front();
                q.pop();

                for (int steps = 1; steps <= 6; steps += 1) {
                    int curr = node + steps;

                    if (flat_board[curr] != -1 && curr != flat_board[curr]) {
                        curr = flat_board[curr];
                    }

                    if (curr == target) {
                        return rolls;
                    }

                    if (seen[curr] == 0) {
                        seen[curr] = 1;
                        q.push(curr);
                    }
                }
            }

            rolls += 1;
        }

        return -1;
    }
};
