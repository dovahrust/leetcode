#define MAX_NUM 100

int minimumOperations(const int *restrict nums, const int len) {
    bool seen[MAX_NUM + 1] = { 0 };
    for (int i = 0; i < len; i += 1) {
        if (nums[i] < 0 || nums[i] > MAX_NUM) { return -1; }

        seen[nums[i]] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= MAX_NUM; i += 1) {
        if (seen[i]) { cnt += 1; }
    }

    return cnt;
}
