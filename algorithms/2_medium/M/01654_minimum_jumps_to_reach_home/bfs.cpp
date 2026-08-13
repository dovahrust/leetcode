constexpr int MAX_ALLOWED = 2'000;

class Solution {
public:
    static int minimumJumps(const vector<int>& forbidden, const int a, const int b, const int x) {
        assert(x >= 0 && a >= 1 && b >= 1 && a <= MAX_ALLOWED && b <= MAX_ALLOWED && x <= MAX_ALLOWED);

        if (x == 0) { return 0; }

        int seen_len = 0;
        if (a >= b) {
            seen_len = x + b + 1;
        } else {
            const int max = *max_element(forbidden.cbegin(), forbidden.cend());
            seen_len = std::max(max, x) + a + b + 1;
        };

        auto seen = vector<pair<bool, bool>>(seen_len, make_pair(false, false));

        for (const int f : forbidden) {
            assert(f >= 1 && f != x);
            if (f < seen_len) {
                seen[f] = make_pair(true, true);
            }
        }

        auto q = deque<pair<int16_t, bool>>();
        q.push_back(make_pair(0, false));
        seen[0] = make_pair(true, true);
        int turns = 0;

        while (!q.empty()) {
            const size_t curr_len = q.size();
            for (size_t steps = 0; steps < curr_len; steps += 1)  {
                const auto [pos_i16, can_back_jump] = q.front();
                q.pop_front();
                const int pos = pos_i16;

                if (pos == x) {
                    return turns;
                }

                if (pos + a < seen_len && !seen[pos + a].first) {
                    seen[pos + a] = make_pair(true, true);
                    q.push_back(make_pair(static_cast<int16_t>(pos + a), true));
                }

                if (can_back_jump && pos - b > 0 && !seen[pos - b].second) {
                    seen[pos - b].second = true;
                    q.push_back(make_pair(static_cast<int16_t>(pos - b), false));
                }
            }

            turns += 1;
        }

        return -1;
    }
};
