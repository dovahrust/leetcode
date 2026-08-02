class Solution {
public:
    static vector<int> evenOddBit(int n) {
        if (n < 0) {
            cerr << "invalid input";
            exit(1);
        }
        int odd = 0;
        int even = 0;
        bool is_odd = true;

        while (n > 0) {
            if ((n & 1) == 1) {
                if (is_odd) {
                    odd += 1;
                } else {
                    even += 1;
                }
            }

            is_odd = !is_odd;
            n >>= 1;
        }

        return vector<int>{ odd, even };
    }
};
