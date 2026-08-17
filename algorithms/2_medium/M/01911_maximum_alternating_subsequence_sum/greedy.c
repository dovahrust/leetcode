long long maxAlternatingSum(const int *restrict nums, const int len){
    if (len <= 0 || nums == NULL) { return -1; }

    int prev_num = 0;
    long long curr_sum = 0;

    for (int i = 0; i < len; i += 1) {
        const int num = nums[i];

        if (num > prev_num) {
            curr_sum += num - prev_num;
        }
        prev_num = num;
    }

    return curr_sum;
}
