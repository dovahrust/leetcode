typedef ptrdiff_t isize;

class Solution {
public:
    static string mergeCharacters(const string& s, const int k_int) {
        const isize len = std::ssize(s);
        const isize k = k_int;
        auto prev_idx = array<isize, 256>();
        std::fill(prev_idx.begin(), prev_idx.end(), -1);
        string stack;
        stack.reserve(len);

        for (const unsigned char ch : s) {
            if (prev_idx[ch] == -1 || std::ssize(stack) - prev_idx[ch] > k) {
                prev_idx[ch] = std::ssize(stack);
                stack.push_back(ch);
            }
        }

        return stack;
    }
};
