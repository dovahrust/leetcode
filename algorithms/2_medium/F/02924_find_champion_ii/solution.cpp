constexpr size_t MAX_ALLOWED = 100;

class Solution {
public:
    static int findChampion(const int n, const vector<vector<int>>& edges) {
        if (n < 1 || static_cast<size_t>(n) > MAX_ALLOWED) {
            fprintf(stderr, "invalid input\n");
            exit(1);
        }

        int8_t parent[MAX_ALLOWED];
        for (int i = 0; i < n; i += 1) { parent[i] = -1; }

        for (const auto& e : edges) {
            const int u = e[0];
            const int v = e[1];

            if (u < 0 || v < 0 || u >= n || v >= n) {
                fprintf(stderr, "invalid input\n");
                exit(1);
            }

            parent[v] = static_cast<int8_t>(u);
        }

        int res = -1;
        for (int i = 0; i < n; i += 1) {
            if (parent[i] == -1) {
                if (res == -1) {
                    res = i;
                } else {
                    return -1;
                }
            }
        }

        return res;
    }
};
