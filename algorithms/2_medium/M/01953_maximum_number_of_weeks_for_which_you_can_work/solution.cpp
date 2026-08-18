class Solution {
public:
    static long long numberOfWeeks(const vector<int>& milestones) {
        const long long max = *std::max_element(milestones.cbegin(), milestones.cend());
        const long long sum_rest = std::reduce(milestones.cbegin(), milestones.cend(), 0LL) - max;

        return sum_rest + std::min(sum_rest + 1, max);
    }
};
