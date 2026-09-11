class Solution {
public:
    static int binaryGap(const int n_int) {
        uint32_t n = static_cast<uint32_t>(n_int);
        while (n > 0 && (n & 1) != 1) {
            n >>= 1;
        }

        int cnt = 0;
        int max = 0;

        while (n > 1) {
            if ((n & 1) == 1) {
                cnt = 1;
            } else {
                cnt += 1;
            }

            max = std::max(max, cnt);
            n >>= 1;
        }

        return max;
    }
};
