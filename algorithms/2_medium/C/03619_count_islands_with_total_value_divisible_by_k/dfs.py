directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

class Solution:
    def dfs_recursive(self, grid, i, j):
        if i < 0 or j < 0 or i >= self.rows or j >= self.cols or grid[i][j] == 0:
            return 0

        total_sum = grid[i][j]
        grid[i][j] = 0

        for (dx, dy) in directions:
            total_sum += self.dfs_recursive(grid, i + dx, j + dy)

        return total_sum

    def countIslands(self, grid: List[List[int]], k: int) -> int:
        count = 0
        self.rows = len(grid)
        self.cols = len(grid[0])

        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] != 0:
                    total_sum = self.dfs_recursive(grid, i, j)
                    if total_sum % k == 0:
                        count += 1

        return count
