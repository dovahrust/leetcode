class Solution {
public:
    static int maxStarSum(const vector<int>& vals, const vector<vector<int>>& edges, const int k_int) {
        const size_t n = vals.size();
        const size_t k = static_cast<size_t>(k_int);
        auto adj_positive_vals = vector<vector<int>>(n, vector<int>());

        for (const auto& e : edges) {
            const int u = e[0];
            const int v = e[1];

            if (vals[v] > 0) {
                adj_positive_vals[u].push_back(vals[v]);
            }

            if (vals[u] > 0) {
                adj_positive_vals[v].push_back(vals[u]);
            }
        }

        for (auto& row : adj_positive_vals) {
            ranges::sort(row, std::greater<>());
        }

        int res = numeric_limits<int>::min();

        for (size_t u = 0; u < n; u += 1) {
            const size_t end = std::min(adj_positive_vals[u].size(), k);
            const int sum = vals[u] + std::reduce(adj_positive_vals[u].cbegin(), adj_positive_vals[u].cbegin() + end, 0);
            res = std::max(res, sum);
        }

        return res;
    }
};
