#define MAX_NUM 100
#define MIN_NUM 1
#define TABLE_LEN (MAX_NUM - MIN_NUM + 1)

int missingMultiple(const int *restrict nums, const int len, const int k) {
    if (k <= 0 || k > MAX_NUM || len <= 0 || nums == NULL) { return -1; }

    bool table[TABLE_LEN] = { false };
    for (int i = 0; i < len; i += 1) {
        const int num = nums[i];
        if (num < MIN_NUM || num > MAX_NUM) {
            return -1;
        }
        table[num - MIN_NUM] = true;
    }

    int i = 0;
    for (i = k; i <= MAX_NUM; i += k) {
        if (!(table[i - MIN_NUM])) {
            return i;
        }
    }

    return i;
}
