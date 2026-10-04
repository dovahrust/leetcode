typedef ptrdiff_t isize;

class Solution {
public:
    static bool checkValidString(const string& s) {
        isize points = 0;
        isize balance = 0;

        for (const char ch : s) {
            if (ch == ')') {
                balance -= 1;

                if (balance < 0) {
                    if (points <= 0) { return false; }

                    points -= 1;
                    balance += 1;
                }
            } else if (ch == '(') {
                balance += 1;
            } else {
                points += 1;
            }
        }

        balance = 0;
        points = 0;

        for (auto it = s.crbegin(); it != s.crend(); it += 1) {
            const char ch = *it;

            if (ch == '(') {
                balance -= 1;

                if (balance < 0) {
                    if (points <= 0) { return false; }

                    points -= 1;
                    balance += 1;
                }
            } else if (ch == ')') {
                balance += 1;
            } else {
                points += 1;
            }
        }

        return true;
    }
};
