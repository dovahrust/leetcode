class Solution {
    inline static bool is_ok(
        span<const char> s,
        span<const char> p,
        span<const char> can_use
    ) {
        const size_t s_len = s.size();
        const size_t p_len = p.size();
        size_t s_idx = 0;
        size_t p_idx = 0;
        while (s_idx < s_len && p_idx < p_len) {
            if (can_use[s_idx] != 0 && s[s_idx] == p[p_idx]) {
                p_idx += 1;
            }

            s_idx += 1;
        }

        return p_idx == p_len;
    }
public:
    static int maximumRemovals(const string& s, const string& p, const vector<int>& removable) {
        ptrdiff_t lo = 0;
        ptrdiff_t hi = std::ssize(removable) - 1;
        auto can_use = vector<char>(s.size());

        while (lo <= hi) {
            const ptrdiff_t mid = lo + (hi - lo) / 2;

            for (auto& c : can_use) { c = 1; }

            for (ptrdiff_t i = 0; i <= mid; i += 1) {
                can_use[removable[i]] = 0;
            }

            if (is_ok(s, p, can_use)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return static_cast<int>(hi + 1);
    }
};
