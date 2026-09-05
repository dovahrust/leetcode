class Solution {
public:
    static int findPoisonedDuration(const vector<int>& time_series,const  int duration) {
        int curr = 0;
        int res = 0;
        for (const int t : time_series) {
            curr = std::max(curr, t);
            res += t + duration - curr;
            curr = t + duration;
        }

        return res;
    }
};
