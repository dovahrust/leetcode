int smallestIndex(const int *restrict nums, const int len) {
    for (int i = 0; i < len; i += 1) {
        int dig_sum = 0;
        int val = nums[i];

        while (val > 0) {
            dig_sum += val % 10;
            val /= 10;
        }

        if (dig_sum == i) {
            return i;
        }
    }

    return -1;
}
