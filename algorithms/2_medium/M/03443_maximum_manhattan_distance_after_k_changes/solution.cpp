struct Data {
    int curr;
    char a;
    char b;
    int k;

    explicit inline Data (const char a, const char b, const int k) noexcept {
        this->a = a;
        this->b = b;
        this->k = k;
        this->curr = 0;
    }

    inline void add(const char ch) noexcept {
        if (ch == a || ch == b) {
            curr += 1;
        } else if (k > 0) {
            k -= 1;
            curr += 1;
        } else {
            curr -= 1;
        }
    }
};

class Solution {
public:
    static int maxDistance(const string& s, int k) {
        assert(s.size() <= 100'000);
        int max = 0;
        auto ne = Data('N', 'E', k);
        auto nw = Data('N', 'W', k);
        auto se = Data('S', 'E', k);
        auto sw = Data('S', 'W', k);

        for (auto it = s.cbegin(); it != s.cend(); it += 1) {
            ne.add(*it);
            nw.add(*it);
            se.add(*it);
            sw.add(*it);

            max = std::max(max, ne.curr);
            max = std::max(max, nw.curr);
            max = std::max(max, se.curr);
            max = std::max(max, sw.curr);
        }

        return max;
    }
};
