class Solution {
public:
    static int eliminateMaximum(const vector<int>& dist, const vector<int>& speed) {
        assert(dist.size() == speed.size());
        const size_t len = dist.size();

        auto arr = vector<int>();
        arr.reserve(len);
        for (size_t i = 0; i < len; i += 1) {
            assert(speed[i] > 0);
            arr.push_back((dist[i] + speed[i] - 1) / speed[i]);
        }
        ranges::sort(arr);

        for (size_t i = 0; i < len; i += 1) {
            if (static_cast<size_t>(arr[i]) < i + 1) {
                return static_cast<int>(i);
            }
        }

        return static_cast<int>(len);
    }
};
