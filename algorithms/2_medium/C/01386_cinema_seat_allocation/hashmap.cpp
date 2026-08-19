class Solution {
public:
    static int maxNumberOfFamilies(const int n, const vector<vector<int>>& reserved_seats) {
        assert(reserved_seats.size() <= 10'000 && n >= 1 && n <= 1'000'000'000);

        auto hashmap = unordered_map<int, uint16_t>();

        for (const auto& r : reserved_seats) {
            assert(r[0] >= 1 && r[0] <= n && r[1] >= 1 && r[1] <= 10);

            if (r[1] == 1 || r[1] == 10) {
                continue;
            }

            const uint16_t curr_col = static_cast<uint16_t>(r[1]);
            const uint16_t mask = (1u << (curr_col - 1)); 
            hashmap[r[0]] |= mask;
        }

        constexpr uint16_t LEFT = 0b0'0001'1110;
        constexpr uint16_t RIGHT = 0b1'1110'0000;
        constexpr uint16_t MID = 0b0'0111'1000;
        int res = (n - static_cast<int>(std::ssize(hashmap))) * 2;

        for (const auto [_, mask] : hashmap) {
            if ((mask & LEFT) == 0 && (mask & RIGHT) == 0) {
                res += 2;
            } else if ((mask & LEFT) == 0 || (mask & RIGHT) == 0 || (mask & MID) == 0) {
                res += 1;
            }
        }

        return res;
    }
};
