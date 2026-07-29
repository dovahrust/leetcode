constexpr size_t max_allowed_freq = 10;

static size_t calc_freqs_smallest_char(const string_view s) {
    char curr_ch = 'z';
    size_t freq = 0;

    for (const char ch : s) {
        if (ch < curr_ch) {
            curr_ch = ch;
            freq = 1;
        } else if (ch == curr_ch) {
            freq += 1;
        }
    }

    return freq;
}

class Solution {
public:
    static vector<int> numSmallerByFrequency(const vector<string>& queries, const vector<string>& words) {
        assert(words.size() <= 2000 && queries.size() <= 2000);

        int16_t prefix[max_allowed_freq + 1] = { 0 };
        for (const auto& w : words) {
            const size_t freq = calc_freqs_smallest_char(w);
            assert(freq <= max_allowed_freq);
            prefix[freq] += 1;
        }
        for (size_t i = 1; i <= max_allowed_freq; i += 1) {
            prefix[i] += prefix[i - 1];
        }

        auto res = vector<int>();
        res.reserve(queries.size());

        for (const auto& q : queries) {
            const size_t freq = calc_freqs_smallest_char(q);
            if (freq >= max_allowed_freq) {
                res.push_back(0);
            } else {
                res.push_back(prefix[max_allowed_freq] - prefix[freq]);
            }
        }

        return res;
    }
};
