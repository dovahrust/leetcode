int countElements(const int *restrict nums, const int len) {
    int min = INT_MAX;
    int max = INT_MIN;
    int min_cnt = 0;
    int max_cnt = 0;

    for (int i = 0; i < len; i += 1) {
        const int num = nums[i];

        if (min > num) {
            min = num;
            min_cnt = 1;
        } else if (min == num) {
            min_cnt += 1;
        }

        if (max < num) {
            max = num;
            max_cnt = 1;
        } else if (max == num) {
            max_cnt += 1;
        }
    }

    if (min == max) {
        return 0;
    }

    return len - max_cnt - min_cnt;
}
