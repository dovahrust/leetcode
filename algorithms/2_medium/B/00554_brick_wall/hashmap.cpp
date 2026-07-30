class Solution {
public:
    int leastBricks(const vector<vector<int>>& wall) {
        assert(wall.size() <= 10'000);
        int total = static_cast<int>(std::ssize(wall));
        auto hashmap = unordered_map<int64_t, int>();
        for (const auto& w : wall) {
            const size_t cols = w.size();
            assert(cols >= 1);
            int64_t pos = 0;
            for (size_t j = 0; j < cols - 1; j += 1) {
                pos += w[j];
                hashmap[pos] += 1;
            }
        }

        int max_freq = 0;
        for (const auto [_, freq] : hashmap) {
            max_freq = std::max(max_freq, freq);
        }

        return total - max_freq;
    }
};
