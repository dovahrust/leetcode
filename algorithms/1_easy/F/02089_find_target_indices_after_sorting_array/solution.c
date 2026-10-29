/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(const int *restrict nums, const int len, const int target, int *return_len) {
    int start_idx = 0;
    int freq = 0;

    for (int i = 0; i < len; i  += 1) {
        if (nums[i] < target) {
            start_idx += 1;
        } else if (nums[i] == target) {
            freq += 1;
        }
    }

    if (freq == 0) {
        *return_len = 0;
        return NULL;
    }

    int *restrict res = malloc((size_t)freq * sizeof(*res));

    if (res == NULL) {
        *return_len = -1;
        return NULL;
    }

    for (int i = 0; i < freq; i += 1) {
        res[i] = start_idx + i;
    }

    *return_len = freq;
    return res;
}
