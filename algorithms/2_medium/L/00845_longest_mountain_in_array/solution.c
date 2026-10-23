#define INVALID_PREV -1

int longestMountain(const int *restrict arr, const int len) {
    int prev = INVALID_PREV;
    int curr = 0;
    int res = 0;

    for (int i = 1; i < len; i += 1) {
        if (arr[i] > arr[i - 1]) {
            if (curr <= 0) {
                prev = INVALID_PREV;
                curr = 1;
            } else {
                curr += 1;
            }
        } else if (arr[i] == arr[i - 1]) {
            prev = INVALID_PREV;
            curr = 0;
        } else {
            if (curr > 0) {
                prev = curr;
                curr = -1;
            } else {
                curr -= 1;
            }
        }

        if (prev != INVALID_PREV && curr < 0) {
            res = MAX(res, 1 + prev + ABS(curr));
        }
    }

    return res;
}
