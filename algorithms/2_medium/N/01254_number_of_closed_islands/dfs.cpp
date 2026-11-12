typedef ptrdiff_t isize;

constexpr int LAND = 0;
constexpr int WATER = 1;
constexpr int LAND_VISITED = -1;

class Solution {
    static void dfs(
        vector<vector<int>>& grid,
        const isize rows,
        const isize cols,
        const isize i,
        const isize j
    ) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != LAND) { return; }

        grid[i][j] = LAND_VISITED;

        dfs(grid, rows, cols, i + 1, j);
        dfs(grid, rows, cols, i - 1, j);
        dfs(grid, rows, cols, i, j + 1);
        dfs(grid, rows, cols, i, j - 1);
    }
public:
    static int closedIsland(vector<vector<int>>& grid) {
        const isize rows = std::ssize(grid);
        const isize cols = std::ssize(grid[0]);
        int cnt = 0;

        for (isize i = 0; i < rows; i += 1) {
            dfs(grid, rows, cols, i, 0);
            dfs(grid, rows, cols, i, cols - 1);
        }

        for (isize j = 0; j < cols; j += 1) {
            dfs(grid, rows, cols, 0, j);
            dfs(grid, rows, cols, rows - 1, j);
        }

        for (isize i = 0; i < rows; i += 1) {
            for (isize j = 0; j < cols; j += 1) {
                if (grid[i][j] == LAND) {
                    cnt += 1;
                    dfs(grid, rows, cols, i, j);
                }
            }
        }

        return cnt;
    }
};
