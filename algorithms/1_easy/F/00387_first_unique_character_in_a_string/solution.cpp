constexpr size_t INF = numeric_limits<size_t>::max();

enum state {
    NOT_SEEN,
    ONCE_SEEN,
    MULTI_SEEN,
};

class Solution {
public:
    static int firstUniqChar(const string& s) {
        const size_t len = s.size();
        enum state states[256] = { NOT_SEEN };
        size_t first_seen[256] = { 0 };

        for (size_t i = 0; i < len; i += 1) {
            const unsigned char ch = static_cast<unsigned char>(s[i]);

            if (states[ch] == NOT_SEEN) {
                states[ch] = ONCE_SEEN;
                first_seen[ch] = i;
            } else {
                states[ch] = MULTI_SEEN;
            }
        }

        size_t res = INF;

        for (size_t i = 0; i < 256; i += 1) {
            if (states[i] == ONCE_SEEN) {
                res = std::min(res, first_seen[i]);
            }
        }

        if (res == INF) {
            return -1;
        }

        return static_cast<int>(res);
    }
};
