class Solution {
public:
    int findClosest(int x, int y, int z) {
        const int dx = std::abs(z - x);
        const int dy = std::abs(z - y);

        if (dx < dy) {
            return 1;
        } else if (dx > dy) {
            return 2;
        } else {
            return 0;
        }
    }
};
