int getWinner(const int *restrict arr, const int len, const int k) {
    assert(k >= 1 && len >= 2 && arr != NULL);

    int cnt = 0;
    int curr = arr[0];

    // Because all integers are distinct, each comparison has a clear winner.
    // If `curr` wins, its streak increases; otherwise a new winner starts.
    // We only need to scan once: if no element reaches `k` wins before
    // the maximum appears, the maximum itself will win all later comparisons.
    for (int i = 1; i < len; i += 1) {
        if (curr > arr[i]) {
            cnt += 1;
        } else {
            cnt = 1;
            curr = arr[i];
        }

        if (cnt >= k) {
            return curr;
        }
    }

    // The maximum element is guaranteed to win in the end.
    return curr;
}
