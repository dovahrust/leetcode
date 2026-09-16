long long minimumReplacement(const int *restrict nums, const int len) {
    int min = INT_MAX;
    int64_t cnt = 0;

    for (int i = len - 1; i >= 0; i -= 1) {
        const int num = nums[i];

        if (num <= min) {
            min = num;
        } else {
            const int parts = (num + min - 1) / min;
            min = num / parts;
            cnt += parts - 1;
        }
    }

    return cnt;
}
