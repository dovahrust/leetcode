#define MAX_NUM 100

int sumCounts(const int *restrict nums, const int len) {
    int res = 0;

    for (int i = 0; i < len; i += 1) {
        bool seen[MAX_NUM + 1] = { 0 };
        int uniques = 0;
        for (int j = i; j < len; j += 1) {
            if (!seen[nums[j]]) {
                uniques += 1;
                seen[nums[j]] = true;
            }

            res += uniques * uniques;
        }
    }

    return res;
}
