typedef ptrdiff_t isize;

class Solution {
    static int64_t dfs(vector<vector<int>> &grid, const isize i, const isize j, const isize rows, const isize cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) { return 0; }

        const int64_t curr = grid[i][j];
        grid[i][j] = 0;

        return curr +
               dfs(grid, i - 1, j, rows, cols) +
               dfs(grid, i + 1, j, rows, cols) +
               dfs(grid, i, j - 1, rows, cols) +
               dfs(grid, i, j + 1, rows, cols);
    }

public:
    int countIslands(vector<vector<int>>& grid, const int k) {
        int cnt = 0;
        const isize rows = std::ssize(grid);
        const isize cols = std::ssize(grid[0]);

        for (isize i = 0; i < rows; i += 1) {
            for (isize j = 0; j < cols; j += 1) {
                if (grid[i][j] != 0) {
                    const int64_t sum = dfs(grid, i, j, rows, cols);

                    if (sum % k == 0) { cnt += 1; }
                }
            }
        }

        return cnt;
    }
};
