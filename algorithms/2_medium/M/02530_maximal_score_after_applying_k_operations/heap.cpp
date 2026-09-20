class Solution {
public:
    static long long maxKelements(const vector<int>& nums, const int k) {
        auto heap = priority_queue<int>(nums.cbegin(), nums.cend());
        int64_t res = 0;

        for (int steps = 0; steps < k; steps += 1) {
            const int val = heap.top();
            heap.pop();
            res += val;
            heap.push((val + 2) / 3);
        }

        return res;
    }
};
