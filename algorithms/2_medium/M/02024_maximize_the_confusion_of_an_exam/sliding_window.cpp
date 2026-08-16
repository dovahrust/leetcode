class Solution {
public:
    static int maxConsecutiveAnswers(const string& s, const int k_int) {
        if (k_int < 1) { return -1; }
        const size_t k = static_cast<size_t>(k_int);
        const size_t len = s.size();
        size_t cnt_true = 0;
        size_t cnt_false = 0;
        size_t lo = 0;
        size_t max = 0;

        for (size_t hi = 0; hi < len; hi += 1) {
            if (s[hi] == 'T') {
                cnt_true += 1;
            } else if (s[hi] == 'F') {
                cnt_false += 1;
            } else {
                return -1;
            }

            while (cnt_false > k && cnt_true > k) {
                if (s[lo] == 'T') {
                    cnt_true -= 1;
                } else {
                    cnt_false -= 1;
                }

                lo += 1;
            }

            max = std::max(max, cnt_true + cnt_false);
        }

        return static_cast<int>(max);
    }
};
