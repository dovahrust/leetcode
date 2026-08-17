class Solution {
    inline static int calc_h_m(const string& s) {
        const int h = (s[0] - '0') * 10 + s[1] - '0';
        const int m = (s[3] - '0') * 10 + s[4] - '0';

        return h * 60 + m;
    }
public:
    static int numberOfRounds(const string& login_time, const string& logout_time) {
        const int tb = calc_h_m(login_time);
        const int te = calc_h_m(logout_time);

        if (te >= tb) {
            if (te < tb + 15) {
                return 0;
            }

            return (te / 15) - ((tb + 14) / 15);
        }

        return (te / 15) + ((24 * 60 - tb) / 15);
    }
};
