constexpr size_t INF = numeric_limits<size_t>::max();

class Solution {
public:
    static vector<string> maxNumOfSubstrings(const string s) {
        if (s.empty()) { return vector<string>(); }

        const size_t len = s.size();
        size_t seen[26][4] = { 0 };
        for (size_t i = 0; i < 26; i += 1) {
            seen[i][0] = INF; // first_seen
            seen[i][1] = INF; // last_seen
            seen[i][2] = 0;   // mask@last
            seen[i][3] = 0;   // running_mask
        }

        for (size_t i = 0; i < len; i += 1) {
            const size_t ch_idx = (size_t)(s[i] - 'a');
            if (seen[ch_idx][0] == INF) {
                seen[ch_idx][0] = i;
            }

            const size_t mask = 1 << ch_idx;
            for (size_t j = 0; j < 26; j += 1) {
                if (seen[j][0] != INF) {
                    seen[j][3] |= mask;
                }
            }
            seen[ch_idx][1] = i;
            seen[ch_idx][2] = seen[ch_idx][3];
        }

        // Almost Bellman-Ford idea
        for (size_t steps = 0; steps < 26; steps += 1) {
            bool has_update = false;
            for (size_t i = 0; i < 26; i += 1){
                if (seen[i][0] != INF) {
                    for (size_t j = 0; j < 26; j += 1) {
                        const size_t mask_j = 1 << j;
                        if ((seen[i][2] & mask_j) != 0) {
                            if (seen[j][0] < seen[i][0]) {
                                has_update = true;
                                seen[i][0] = seen[j][0];
                            }

                            if (seen[j][1] > seen[i][1]) {
                                has_update = true;
                                seen[i][1] = seen[j][1];
                            }
                        }
                    }
                }
            }

            if (!has_update) {
                break;
            }
        }

        auto res = vector<string>();
        auto valids = vector<pair<size_t, size_t>>();
        for (size_t i = 0; i < 26; i += 1) {
            if (seen[i][0] != INF) {
                valids.push_back({ seen[i][0], seen[i][1] });
            }
        }
        ranges::sort(valids, [](const auto a, const auto b) {
            return a.second < b.second;
        });

        res.push_back(s.substr(valids[0].first, valids[0].second - valids[0].first + 1));

        size_t prev_end = valids[0].second;
        for (const auto [lo, hi] : valids) {
            if (lo > prev_end) {
                prev_end = hi;
                res.push_back(s.substr(lo, hi - lo + 1));
            }
        }

        return res;
    }
};
