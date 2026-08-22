constexpr int64_t MOD = 1'000'000'007;

struct Pair {
    int64_t max;
    int64_t min;

    Pair(int64_t max, int64_t min) {
        this->max = max;
        this->min = min;
    }
};

class Solution {
public:
    static int maxProductPath(const vector<vector<int>>& grid) {
        assert(!grid.empty() && !grid[0].empty());
        const size_t rows = grid.size();
        const size_t cols = grid[0].size();
        auto buff = vector<Pair>(2 * cols, Pair(0, 0));
        auto prev = span<Pair>(&buff[0], cols);
        auto curr = span<Pair>(&buff[cols], cols);

        prev[0] = Pair(grid[0][0], grid[0][0]);
        for (size_t j = 1; j < cols; j += 1) {
            const int64_t v = prev[j - 1].min * grid[0][j];
            prev[j] = Pair(v, v);
        }

        for (size_t i = 1; i < rows; i += 1) {
            const int64_t v = prev[0].min * grid[i][0];
            curr[0] = Pair(v, v);

            for (size_t j = 1; j < cols; j += 1) {
                const int64_t cell = grid[i][j];
                const int64_t a = prev[j].min * cell;
                const int64_t b = prev[j].max * cell;
                const int64_t c = curr[j - 1].min * cell;
                const int64_t d = curr[j - 1].max * cell;

                curr[j] = Pair(
                    std::max(std::max(a, b), std::max(c, d)),
                    std::min(std::min(a, b), std::min(c, d))
                );
            }
            std::swap(prev, curr);
        }

        if (prev[cols - 1].max < 0) {
            return -1;
        }

        return static_cast<int>(prev[cols - 1].max % MOD);
    }
};
