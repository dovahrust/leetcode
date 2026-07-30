class Solution {
public:
    static int minimumPushes(const string& word) {
        assert(std::ssize(word) <= 26);
        const int n = std::ssize(word);

        return n + (n - std::min(n, 8)) + (n - std::min(n, 16)) +  (n - std::min(n, 24));
    }
};
