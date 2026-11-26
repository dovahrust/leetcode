class Solution {
public:
    static bool canAliceWin(int n) {
        int step = 10;
        bool is_winning = false;

        while (step > 0 && step <= n) {
            n -= step;
            step -= 1;
            is_winning = !is_winning;
        }

        return is_winning;
    }
};
