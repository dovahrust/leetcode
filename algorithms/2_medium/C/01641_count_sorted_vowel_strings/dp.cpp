class Solution {
public:
    int countVowelStrings(int n) {
        assert(n >= 1 && n <= 50);

        int buff[10] = { 0 };
        auto prev = span<int>(&buff[0], 5);
        for (int i = 0; i < 5; i += 1) { prev[i] = 1; }
        auto curr = span<int>(&buff[5], 5);

        for (int steps = 1; steps < n; steps += 1) {
            for (int i = 0; i < 5; i += 1) {
                curr[i] = 0;
            }

            for (int i = 0; i < 5; i += 1) {
                for (int j = 0; j <= i; j += 1) {
                    curr[j] += prev[i];
                }
            }

            std::swap(prev, curr);
        }

        return std::reduce(prev.cbegin(), prev.cend(), 0);
    }
};
