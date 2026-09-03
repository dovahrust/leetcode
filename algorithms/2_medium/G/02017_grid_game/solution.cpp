class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        if (grid.size() != 2) { return -1; }
        if (grid[0].size() <= 1) { return 0; }

        const size_t cols = grid[0].size();
        int64_t u = reduce(grid[0].cbegin() + 1, grid[0].cend(), 0LL);
        int64_t d = 0;
        int64_t res = u;

        for (size_t j = 1; j < cols; j += 1) {
            u -= grid[0][j];
            d += grid[1][j - 1];
            res = std::min(res, std::max(u, d));
        }

        return res;
    }
};
