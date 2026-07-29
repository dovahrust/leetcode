class Solution {
public:
    static vector<vector<int>> aggregateTimeSeries(const vector<vector<int>>& series1, const vector<vector<int>>& series2) {
        const size_t len1 = series1.size();
        const size_t len2 = series2.size();
        auto res = vector<vector<int>>();
        res.reserve(len1 + len2);
        size_t i1 = 0;
        size_t i2 = 0;

        while (i1 < len1 && i2 < len2) {
            const int time_min = std::min(series1[i1][0], series2[i2][0]);
            const int val = series1[i1][1] + series2[i2][1];
            res.push_back(vector<int>{time_min, val});

            if (series1[i1][0] == time_min) {
                i1 += 1;
            }

            if (series2[i2][0] == time_min) {
                i2 += 1;
            }
        }

        while (i1 < len1)  {
            res.push_back(series1[i1]);
            i1 += 1;
        }

        while (i2 < len2)  {
            res.push_back(series2[i2]);
            i2 += 1;
        }

        return res;
    }
};
