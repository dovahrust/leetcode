class Solution {
public:
    static vector<int> stableMountains(const vector<int>& height, const int threshold) {
        const size_t len = height.size();
        auto res = vector<int>();

        for (size_t i = 1; i < len; i += 1) {
            if (height[i - 1] > threshold) {
                res.push_back(static_cast<int>(i));
            }
        }

        return res;
    }
};
