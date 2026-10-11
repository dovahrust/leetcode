int sumOfSquares(const int *restrict nums, const int len) {
    int res = 0;
    const int sqrt_len = sqrt(len);
    for (int i = 1; i <= sqrt_len; ++i) {
        if (len % i == 0) {
            const int other_idx = len / i;
            res += nums[i - 1] * nums[i - 1];
            if (other_idx != i) {
                res += nums[other_idx - 1] * nums[other_idx - 1];
            }
        }
    }

    return res;
}
