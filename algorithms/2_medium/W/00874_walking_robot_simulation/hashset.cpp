constexpr size_t dir_len = 4;
constexpr int directions [dir_len][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
    struct PairHash {
        std::size_t operator()(const std::pair<int, int>& p) const {
            static const auto hash_func = std::hash<int>();
            const auto h1 = hash_func(p.first);
            const auto h2 = hash_func(p.second);
            return h1 ^ (h2 << 1);
        }
    };
public:
    int robotSim(const vector<int>& commands, const vector<vector<int>>& obstacles) {
        assert(all_of(obstacles.cbegin(), obstacles.cend(), [](const auto& a){
            return std::ssize(a) == 2;
        }));
        auto hashset = unordered_set<pair<int, int>, PairHash>();
        for (const auto& o : obstacles) {
            hashset.insert(make_pair(o[0], o[1]));
        }
        int x = 0;
        int y = 0;
        size_t dir_idx = 0;
        int max = 0;
        for (const int c : commands) {
            switch (c) {
                case -2:
                    dir_idx = (dir_idx + dir_len - 1) % dir_len;
                    break;
                case -1:
                    dir_idx = (dir_idx + 1) % dir_len;
                    break;
                default: {
                    if (c < 1 || c > 9) {
                        cerr << "invalid input";
                        exit(1);
                    }
                    const auto [dx, dy] = directions[dir_idx];
                    for (int steps = 1; steps <= c; steps += 1) {
                        if (hashset.contains(make_pair(x + dx, y + dy))) {
                            break;
                        }
                        x += dx;
                        y += dy;
                        max = std::max(max, x * x + y * y);
                    }
                    break;
                }
            }
        }

        return max;
    }
};
