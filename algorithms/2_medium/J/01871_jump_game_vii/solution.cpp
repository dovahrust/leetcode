class Solution {
public:
    static bool canReach(const string& s, const int min_jump, const int max_jump) {
        const ptrdiff_t len = std::ssize(s);
        if (min_jump < 1 || min_jump > max_jump || len < 2 || len > 100'000) {
            std::cerr << "invalid input" << std::endl;
            exit(1);
        }

        if (s[len - 1] != '0' || s[0] != '0') { return false; }

        auto diff = vector<int>(len + 1, 0);
        diff[0] = 1;
        diff[1] = -1;

        int balance = 0;
        for (ptrdiff_t i = 0; i < len; i += 1) {
            balance += diff[i];
            if (balance > 0) {
                if (i == len - 1) {
                    return true;
                }

                if (s[i] != '0') {
                    continue;
                }

                const ptrdiff_t begin = std::min(i + min_jump, len);
                const ptrdiff_t end = std::min(i + max_jump + 1, len);

                diff[begin] += 1;
                diff[end] -= 1;
            }
        }

        return false;
    }
};
