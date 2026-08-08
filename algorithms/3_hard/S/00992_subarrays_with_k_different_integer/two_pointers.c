static int at_most(const int *restrict nums, const int len, const int k, int *restrict freqs) {
    for (int i = 0; i < len + 1; i += 1) {
        freqs[i] = 0;
    }
    int uniques = 0;
    int res = 0;
    int lo = 0;

    for (int hi = 0; hi < len; hi += 1) {
        assert(nums[hi] > 0 && nums[hi] <= len);
        if (freqs[nums[hi]] == 0) {
            uniques += 1;
        }
        freqs[nums[hi]] += 1;
        while (uniques > k) {
            freqs[nums[lo]] -= 1;
            if (freqs[nums[lo]] == 0) {
                uniques -= 1;
            }
            lo += 1;
        }

        res += hi - lo + 1;
    }

    return res;
}

int subarraysWithKDistinct(const int *restrict nums, const int len, const int k) {
    if (k < 1 || k > len || len > 20000 || nums == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    int* freqs = malloc((size_t)(len + 1) * sizeof(*freqs));
    if (freqs == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }

    const int res = at_most(nums, len, k, freqs) - at_most(nums, len, k - 1, freqs);
/* cleanup: */
    free(freqs);
    return res;
}
