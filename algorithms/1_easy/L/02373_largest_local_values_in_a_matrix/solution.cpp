class Solution {
public:
    static vector<vector<int>> largestLocal(const vector<vector<int>>& grid) {
        const size_t n = grid.size();
        assert(n >= 3 && n == grid[0].size());
        auto res =  vector<vector<int>>();
        res.reserve(n - 2);

        for (size_t i = 0; i < n - 2; i += 1) {
            auto tmp = vector<int>();
            tmp.reserve(n - 2);

            for (size_t j = 0; j < n - 2; j += 1) {
                int max = numeric_limits<int>::min();
                for (size_t ofs_i = 0; ofs_i < 3; ofs_i += 1) {
                    for (size_t ofs_j = 0; ofs_j < 3; ofs_j += 1) {
                        max = std::max(max, grid[i + ofs_i][j + ofs_j]);
                    }
                }
                tmp.push_back(max);
            }

            res.push_back(tmp);
        }

        return res;
    }
};
