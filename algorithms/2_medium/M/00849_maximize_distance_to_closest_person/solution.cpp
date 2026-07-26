typedef ptrdiff_t isize;

class Solution {
public:
    static int maxDistToClosest(const span<int> seats) {
        assert(any_of(seats.cbegin(), seats.cend(), [](const int a) { return a == 0; }));
        assert(any_of(seats.cbegin(), seats.cend(), [](const int a) { return a == 1; }));

        const isize len = std::ssize(seats);
        isize prev = -1;
        isize res = 0;
        for (isize i = 0; i < len; i += 1) {
            assert(seats[i] == 0 || seats[i] == 1);

            if (seats[i] == 1) {
                switch (prev) {
                    case -1:
                        res = i;
                        break;
                    default:
                        res = std::max(res, (i - prev) / 2);
                        break;
                }

                prev = i;
            }
        }
        res = std::max(res, len - 1 - prev);

        assert(res <= numeric_limits<int>::max());
        return static_cast<int>(res);
    }
};
