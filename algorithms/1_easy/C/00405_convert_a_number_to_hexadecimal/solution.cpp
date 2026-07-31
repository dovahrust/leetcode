class Solution {
public:
    static string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        unsigned int u_num = static_cast<unsigned int>(num);
        auto res= string();
        res.reserve(8);

        while (u_num > 0) {
            const unsigned int curr_dig = u_num % 16;
            u_num /= 16;

            if (curr_dig > 9) {
                res.push_back(curr_dig - 10 + 'a');
            } else {
                res.push_back(curr_dig + '0');
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
