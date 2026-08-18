#define MAX_NUM 50
#define MIN_NUM 0
#define TABLE_LEN (MAX_NUM - MIN_NUM + 1)

int largestInteger(const int *restrict nums, const int len, const int k) {
    if (len == 0 || nums == NULL || k > len || k < 0) { return -1; }

    int res = -1;

    if (k == len) {
        for (int i = 0; i < len; i += 1) {
            res = MAX(res, nums[i]);
        }
    } else if (k == 1) {
        int freqs[TABLE_LEN] = { 0 };

        for (int i = 0; i < len; i += 1) {
            if (nums[i] < MIN_NUM || nums[i] > MAX_NUM) { return -1; }

            freqs[nums[i] - MIN_NUM] += 1;
        }

        for (int i = TABLE_LEN - 1; i >= 0; i -= 1) {
            if (freqs[i] == 1) {
                res = i + MIN_NUM;
                break;
            }
        }
    } else {
        const int first = nums[0];
        const int last = nums[len - 1];
        int cnt_first = 0;
        int cnt_last = 0;

        for (int i = 0; i < len; i += 1) {
            if (nums[i] == first) {
                cnt_first += 1;
            }

            if (nums[i] == last) {
                cnt_last += 1;
            }
        }

        if (cnt_first == 1 && cnt_last == 1) {
            res = MAX(first, last);
        } else if (cnt_first == 1) {
            res = first;
        } else if (cnt_last == 1) {
            res = last;
        }
    }

    return res;
}
