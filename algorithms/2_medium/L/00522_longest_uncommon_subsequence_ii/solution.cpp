typedef ptrdiff_t isize;

class Solution {
    inline static bool is_sub(const string& a, const string& b) {
        const size_t a_len = a.size();
        const size_t b_len = b.size();

        if (a_len > b_len) {
            return false;
        }

        size_t a_idx = 0;
        size_t b_idx = 0;

        while (a_idx < a_len && b_idx < b_len) {
            if (a[a_idx] == b[b_idx]) {
                a_idx += 1;
            }
            b_idx += 1;
        }

        return a_idx == a_len;
    }
public:
    int findLUSlength(vector<string>& strs) {
        const size_t len = strs.size();
        assert(len >= 2);
        isize res = -1;
        for (size_t i = 0; i < len; i += 1) {
            for (size_t j = 0; j < len; j += 1) {
                if (i == j) { continue; }

                if (is_sub(strs[i], strs[j])) {
                    goto continue_main_loop;
                }
            }

            res = std::max(res, std::ssize(strs[i]));

            continue_main_loop:
                continue;
        }

        assert(res <= numeric_limits<int>::max());
        return static_cast<int>(res);
    }
};
