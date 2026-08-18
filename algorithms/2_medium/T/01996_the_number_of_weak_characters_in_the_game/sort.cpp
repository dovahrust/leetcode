class Solution {
public:
    static int numberOfWeakCharacters(vector<vector<int>>& properties) {
        assert(properties.size() >= 2);

        ranges::sort(properties, [](const auto& a, const auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] > b[0];
            }
        });

        int64_t cnt = 0;
        int curr_max = numeric_limits<int>::min();
        int level = properties[0][0];
        int level_max = properties[0][1];

        for (const auto& p : properties) {
            if (p[0] < level) {
                curr_max = std::max(curr_max, level_max);
                level = p[0];
                level_max = p[1];
            }

            if (p[1] < curr_max) {
                cnt += 1;
            }
        }

        assert(cnt <= numeric_limits<int>::max());
        return static_cast<int>(cnt);
    }
};
