typedef ptrdiff_t isize;

class Solution {
public:
    static long long maxPoints(const vector<vector<int>>& points) {
        assert(!points.empty() && !points[0].empty());
        const isize rows = std::ssize(points);
        const isize cols = std::ssize(points[0]);
        auto buff = vector<int64_t>(2 * cols, 0);
        auto curr = span<int64_t>(&buff[0], cols);
        auto prev = span<int64_t>(&buff[cols], cols);

        for (isize i = 0; i < rows; i += 1) {
            int64_t curr_max = 0;
            for (isize j = 0; j < cols; j += 1) {
                assert(points[i][j] >= 0 && points[i][j] <= 100'000);
                curr_max -= 1;
                curr_max = std::max(curr_max, prev[j]);
                curr[j] = curr_max + points[i][j];
            }

            curr_max = 0;
            for (isize j = cols - 1; j >= 0; j -= 1) {
                curr_max -= 1;
                curr_max = std::max(curr_max, prev[j]);
                curr[j] = std::max(curr[j], curr_max + points[i][j]);
            }

            std::swap(curr, prev);
        }

        return *std::max_element(prev.cbegin(), prev.cend());
    }
};
