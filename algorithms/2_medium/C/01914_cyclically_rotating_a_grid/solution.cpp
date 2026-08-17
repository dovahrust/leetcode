typedef ptrdiff_t isize;

class Solution {
public:
    static vector<vector<int>> rotateGrid(const vector<vector<int>>& grid, const int k) {
        assert(k >= 1 && grid.size() > 0 && grid[0].size() > 0);
        const isize rows = std::ssize(grid);
        const isize cols = std::ssize(grid[0]);
        assert((rows & 1) == 0 && (cols & 1) == 0);

        auto res = vector<vector<int>>(rows, vector<int>(cols));
        auto buff = vector<int>();
        buff.reserve(2 * (rows + cols));

        isize i_lo = 0;
        isize i_hi = rows - 1;
        isize j_lo = 0;
        isize j_hi = cols - 1;

        while (i_lo < i_hi && j_lo < j_hi) {
            buff.clear();
            for (isize i = i_lo; i <= i_hi; i += 1) {
                buff.push_back(grid[i][j_lo]);
            }
            for (isize j = j_lo + 1; j <= j_hi; j += 1) {
                buff.push_back(grid[i_hi][j]);
            }
            for (isize i = i_hi - 1; i >= i_lo; i -= 1) {
                buff.push_back(grid[i][j_hi]);
            }
            for (isize j = j_hi - 1; j >= j_lo + 1; j -= 1) {
                buff.push_back(grid[i_lo][j]);
            }
            const isize need = std::ssize(buff) - k % std::ssize(buff);
            reverse(buff.begin(), buff.begin() + need);
            reverse(buff.begin() + need, buff.end());
            reverse(buff.begin(), buff.end());
            isize idx = 0;
            for (isize i = i_lo; i <= i_hi; i += 1) {
                res[i][j_lo] = buff[idx];
                idx += 1;
            }
            for (isize j = j_lo + 1; j <= j_hi; j += 1) {
                res[i_hi][j] = buff[idx];
                idx += 1;
            }
            for (isize i = i_hi - 1; i >= i_lo; i -= 1) {
                res[i][j_hi] = buff[idx];
                idx += 1;
            }
            for (isize j = j_hi - 1; j >= j_lo + 1; j -= 1) {
                res[i_lo][j] = buff[idx];
                idx += 1;
            }
            i_lo += 1;
            i_hi -= 1;
            j_lo += 1;
            j_hi -= 1;
        }

        return res;
    }
};
