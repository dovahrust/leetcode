class HeapWithSum : public priority_queue<int, vector<int>, std::less<int>> {
public:
    using std::priority_queue<int, vector<int>, std::less<int>>::priority_queue;

    int sum() const {
        return reduce(this->c.begin(), this->c.end(), 0);
    }
};

class Solution {
public:
    static int minStoneSum(const vector<int>& piles, const int k) {
        auto heap = HeapWithSum(piles.cbegin(), piles.cend());
        for (int i = 0; i < k; i += 1) {
            const int v = heap.top();
            heap.pop();
            heap.push(v - (v / 2));
        }
        return heap.sum();
    }
};
