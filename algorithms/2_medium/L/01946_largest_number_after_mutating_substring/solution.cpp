constexpr size_t CHANGE_LEN = 10;

class Solution {
    static inline bool can_improve_by_change(const vector<int>& change_vec) {
        for (size_t i = 0; i < CHANGE_LEN; i += 1) {
            if (i < change_vec[i]) {
                return true;
            }
        }
        return false;
    }
public:
    static string maximumNumber(string num, const vector<int>& change_vec) {
        assert(change_vec.size() == CHANGE_LEN);

        if (!can_improve_by_change(change_vec)) {
            return num;
        }

        char change[CHANGE_LEN];
        for (size_t i = 0; i < CHANGE_LEN; i += 1) {
            const int x = change_vec[i];
            assert(x >= 0 && x <= 9);
            change[i] = static_cast<char>('0' + change_vec[i]);
        }

        bool has_changed = false;
        for (char& ch : num) {
            assert(ch >= '0' && ch <= '9');
            const size_t idx = static_cast<size_t>(ch - '0');
            if (ch < change[idx]) {
                ch = change[idx];
                has_changed = true;
            } else if (has_changed && ch != change[idx]) {
                break;
            }
        }

        return num;
    }
};
