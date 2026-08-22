class Solution {
public:
    static vector<int> findSmallestSetOfVertices(const int n, const vector<vector<int>>& edges) {
        assert(n >= 2 && n <= 100'000);
        auto has_parent = vector<bool>(n, false);

        for (const auto& e : edges) {
            const int u = e[0];
            const int v = e[1];
            assert(u >= 0 && u < n && v >= 0 && v < n);
            has_parent[v] = true;
        }

        auto res = vector<int>();
        for (int i = 0; i < n; i += 1) {
            if (!has_parent[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};
