class Solution {
public:
    static vector<int> xorQueries(const vector<int>& arr, const vector<vector<int>>& queries) {
        const size_t arr_len = arr.size();
        auto prefix = vector<int>(arr_len + 1);
        prefix[0] = 0;
        for (size_t i = 0; i < arr_len; i += 1) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        auto res = vector<int>();
        res.reserve(queries.size());

        for (const auto& query : queries) {
            assert(query.size() == 2);
            const int lo = query[0];
            const int hi = query[1];
            assert(lo >= 0 && hi >= lo && static_cast<size_t>(hi) < arr_len);
            res.push_back(prefix[hi + 1] ^ prefix[lo]);
        }

        return res;
    }
};
