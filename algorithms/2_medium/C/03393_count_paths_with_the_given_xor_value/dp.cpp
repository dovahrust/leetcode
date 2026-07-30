typedef ptrdiff_t isize;

constexpr int max_num = 15;
constexpr int mod = 1'000'000'007;

class Solution {
public:
    int countPathsWithXorValue(const vector<vector<int>>& grid, int k) {
        assert(grid.size() > 0 && grid[0].size() > 0 && k >= 0 && k <= max_num);

        const isize rows = std::ssize(grid);
        const isize cols = std::ssize(grid[0]);
        auto buff = vector<int>((2 * cols * (max_num + 1)), 0);
        auto prev = span<int>(&buff[0], cols * (max_num + 1));
        auto curr = span<int>(&buff[cols * (max_num + 1)], cols * (max_num + 1));

        int curr_xor = 0;
        for (int j = 0; j < cols; j += 1) {
            const int v = grid[0][j];
            assert(v >= 0 && v <= max_num);
            curr_xor ^= v;
            prev[j * (max_num + 1) + curr_xor] = 1;
        }

        for (isize i = 1; i < rows; i += 1) {
            for (isize j = 0; j < cols; j += 1) {
                const int v = grid[i][j];
                assert(v >= 0 && v <= max_num);
                for (int prev_val = 0; prev_val <= max_num; prev_val += 1)  {
                    const int curr_idx = j * (max_num + 1) + (prev_val ^ v);
                    const int up_idx = j * (max_num + 1) + prev_val;

                    curr[curr_idx] = prev[up_idx];
                }

                if (j > 0) {
                    for (int prev_val = 0; prev_val <= max_num; prev_val += 1)  {
                        const int curr_idx = j * (max_num + 1) + (prev_val ^ v);
                        const int left_idx = (j - 1) * (max_num + 1) + prev_val;

                        curr[curr_idx] = (curr[curr_idx] + curr[left_idx]) % mod;
                    }
                }
            }

            std::swap(curr, prev);
            for (auto& v : curr) {
                v = 0;
            }
        }

        const isize target_idx = (cols - 1) * (max_num + 1) + k;
        return prev[target_idx];
    }
};
