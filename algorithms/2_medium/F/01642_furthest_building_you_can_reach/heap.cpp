class Solution {
public:
    static int furthestBuilding(const vector<int>& heights, int bricks, int ladders) {
        if (heights.empty()) { return -1; }

        const size_t len = heights.size();
        auto heap = priority_queue<int>();

        for (size_t idx = 0; idx + 1 < len; idx += 1) {
            if (heights[idx] < heights[idx + 1]) {
                const int need = heights[idx + 1] - heights[idx];
                bricks -= need;
                heap.push(need);
                if (bricks < 0) {
                    bricks += heap.top();
                    heap.pop();
                    ladders -= 1;
                    if (ladders < 0) {
                        return static_cast<int>(idx);
                    }
                }
            }
        }

        return static_cast<int>(len - 1);
    }
};
