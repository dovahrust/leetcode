class Solution {
    inline static string_view get_letters(const char ch) {
        switch (ch) {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: abort();
        }
    }

    static void backtrack(
        const string_view digits,
        const size_t idx,
        string& tmp,
        vector<string>& res
    ) {
        if (idx == digits.size()) {
            res.push_back(tmp);
            return;
        }

        for (const char ch: get_letters(digits[idx])) {
            tmp.push_back(ch);
            backtrack(digits, idx + 1, tmp, res);
            tmp.pop_back();
        }

    }
public:
    static vector<string> letterCombinations(const string& digits) {
        if (digits.empty()) { return vector<string>(); }

        auto res = vector<string>();
        auto tmp = string();

        backtrack(digits, 0, tmp, res);

        return res;
    }
};
