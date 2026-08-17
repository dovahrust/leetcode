typedef ptrdiff_t isize;

class Solution {
    static bool dfs_is_sub(
        const vector<vector<int>>& g1,
        const vector<vector<int>>& g2,
        const isize rows, const isize cols,
        const isize i, const isize j,
        vector<int8_t>& seen
    ) {
        if (i < 0 || j < 0 || i >= rows || j >= cols) {
            return true;
        }
        if (seen[i * cols + j] == 1 || g2[i][j] == 0) {
            return true;
        }

        bool res = true;
        seen[i * cols + j] = 1;

        if (g1[i][j] == 0) {
            res = false;
        }

        res &= dfs_is_sub(g1, g2, rows, cols, i + 1, j, seen);
        res &= dfs_is_sub(g1, g2, rows, cols, i - 1, j, seen);
        res &= dfs_is_sub(g1, g2, rows, cols, i, j + 1, seen);
        res &= dfs_is_sub(g1, g2, rows, cols, i, j - 1, seen);

        return res;
    }
public:
    static int countSubIslands(const vector<vector<int>>& grid1, const vector<vector<int>>& grid2) {
        assert(
            grid1.size() != 0 && grid1.size() == grid2.size() && grid1.size() <= 500 &&
            grid1[0].size() != 0 && grid1[0].size() == grid2[0].size() && grid1[0].size() <= 500
        );

        const isize rows = std::ssize(grid1);
        const isize cols = std::ssize(grid1[0]);
        auto seen = vector<int8_t>(rows * cols, 0);
        int cnt = 0;

        for (isize i = 0; i < rows; i += 1) {
            for (isize j = 0; j < cols; j += 1) {
                if (!seen[i * cols + j] && grid2[i][j] == 1) {
                    if (dfs_is_sub(grid1, grid2, rows, cols, i, j, seen)) {
                        cnt += 1;
                    }
                }
            }
        }

        return cnt;
    }
};
