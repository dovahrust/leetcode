bool isMonotonic(const int* nums, const int len) {
    if (len <= 1) {
        return true;
    }

    if (nums == NULL) {
        fprintf(stderr, "invalid input\n");
        exit(1);
    }

    int state = 0;

    for (int i = 1; i < len; i += 1) {
        if (nums[i] > nums[i - 1]) {
            if (state == -1) {
                return false;
            }
            state = 1;
        } else if (nums[i] < nums[i - 1]) {
            if (state == 1) {
                return false;
            }
            state = -1;
        }
    }

    return true;
}
