class Solution {
public:
    static int maxFreeTime(
        const int event_time,
        const int k_int,
        const vector<int>& start_time,
        const vector<int>& end_time
    ) {
        assert(start_time.size() == end_time.size() && k_int >= 1 && event_time >= 1);
        const size_t len = start_time.size();
        const size_t k = static_cast<size_t>(k_int);

        auto prefix = vector<int>(len + 2);
        prefix[0] = 0;
        int prev_end = 0;
        for (size_t i = 0; i < len; i += 1) {
            prefix[i + 1] = prefix[i] + start_time[i] - prev_end;
            prev_end = end_time[i];
        }
        prefix[len + 1] = event_time - prev_end + prefix[len];

        int res = 0;
        for (size_t i = k - 1; i < len; i += 1) {
            const int curr = prefix[i + 2] - prefix[i - (k - 1)];
            res = std::max(res, curr);
        }

        return res;
    }
};
