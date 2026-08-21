class Solution {
    unordered_map<int, int> map;
    int range;
    int m;
    int n;
public:
    Solution(int m, int n) {
        assert(n >= 1 && m >= 1 && n <= 10'000 && m <= 10'000);
        this->m = m;
        this->n = n;
        range = m * n;
    }

    vector<int> flip() {
        if (range == 0) {
            return vector<int>();
        }

        const int random_value = static_cast<int>(random() % range);
        int res;
        {
            auto it = map.find(random_value);
            if (it != map.end()) {
                res = it->second;
            } else {
                res = random_value;
            }
        }

        range -= 1;
        auto it = map.find(range);
        if (it != map.end()) {
            map[random_value] = it->second;
        } else {
            map[random_value] = range;
        }

        return vector<int>{res / n, res % n};
    }

    void reset() {
        map.clear();
        range = n * m;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
