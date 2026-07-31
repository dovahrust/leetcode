class Solution {
public:
    static vector<string> readBinaryWatch(const int turned_on) {
        auto res = vector<string>();

        for (int h = 0; h <= 11; h += 1) {
            for (int m = 0; m <= 59; m += 1) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turned_on) {
                    if (m < 10) {
                        res.push_back(format("{}:0{}", h, m));
                    } else {
                        res.push_back(format("{}:{}", h, m));
                    }
                }
            }
        }

        return res;
    }
};
