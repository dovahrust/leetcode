constexpr int MAX_NUM = 70;
constexpr int MIN_NUM = 1;

class Solution {
public:
    static int minimizeTheDifference(const vector<vector<int>>& mat, const int target) {
        if (mat.size() <= 0 || mat.size() > 70 || mat[0].size() <= 0 || mat[0].size() > 70) {
            return -1;
        }
        const int rows = static_cast<int>(std::ssize(mat));
        const int cols = static_cast<int>(std::ssize(mat[0]));

        const int states_len = (MAX_NUM + 1) * rows;
        auto buff = vector<int8_t>(2 * states_len, 0);
        auto prev = span<int8_t>(&buff[0], states_len);
        auto curr = span<int8_t>(&buff[states_len], states_len);
        prev[0] = 1;

        for (const auto& line : mat) {
            for (int k = 0; k < states_len; k += 1) {
                if (prev[k] == 0) { continue; }

                for (const int v : line) {
                    if (v < MIN_NUM || v > MAX_NUM) {
                        return -1;
                    }
                    curr[k + v] = 1;
                }
            }

            auto temp = curr;
            curr = prev;
            prev = temp;
            for (int k = 0; k < states_len; k += 1) {
                curr[k] = 0;
            }
        }

        int min = numeric_limits<int>::max();
        for (int i = 0; i < states_len; i += 1) {
            if (prev[i] == 1) {
                min = std::min(min, std::abs(i - target));
            }
        }

        return min;
    }
};
