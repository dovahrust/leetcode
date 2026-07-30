static inline int16_t max_int16(const int16_t a, const int16_t b) {
    return a > b ? a : b;
}

int findLength(const int* nums1, const int nums1_len, const int* nums2, const int nums2_len) {
    assert(nums1_len >= 0 && nums2_len >= 0 && nums1_len <= 1000 && nums2_len <= 1000);
    if (nums1_len == 0 || nums2_len == 0) { return 0; }
    assert(nums1 != NULL && nums2 != NULL);

    const int* n1 = nums1_len >= nums2_len ? nums1 : nums2;
    const int len1 = nums1_len >= nums2_len ? nums1_len : nums2_len;

    const int* n2 = nums1_len >= nums2_len ? nums2 : nums1;
    const int len2 = nums1_len >= nums2_len ? nums2_len : nums1_len;

    int16_t* buff = calloc(2U * (size_t)(len2 + 1), sizeof(*buff));
    assert(buff != NULL);
    int16_t* curr = &buff[0];
    int16_t* next = &buff[len2 + 1];
    int16_t res = 0;

    for (int i = len1 - 1; i >= 0; i -= 1) {
        for (int j = len2 - 1; j >= 0; j -= 1) {
            if (n1[i] == n2[j]) {
                const int16_t val = 1 + next[j + 1];
                curr[j] = val;
                res = max_int16(res, val);
            }
        }
        int16_t* temp = curr;
        curr = next;
        next = temp;
        for (int j = 0; j < len2 + 1; j += 1) {
            curr[j] = 0;
        }
    }

/* cleanup: */
    free(buff);
    return res;
}
