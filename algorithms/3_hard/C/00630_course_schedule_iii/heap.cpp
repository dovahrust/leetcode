class Solution {
public:
    static int scheduleCourse(vector<vector<int>>& courses) {
        ranges::sort(courses, [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        auto heap = priority_queue<int>();
        int sum = 0;

        for (const auto& c : courses) {
            sum += c[0];
            const int max_allowed = c[1];
            heap.push(c[0]);

            if (sum > max_allowed) {
                sum -= heap.top();
                heap.pop();
            }
        }

        return static_cast<int>(std::ssize(heap));
    }
};
