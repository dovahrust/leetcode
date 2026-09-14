int numOfSubarrays(const int *restrict arr, const int len, const int k, const int threshold) {
    if (k <= 0 || threshold < 0) { return -1; }

    if (k > len) { return 0; }

    const int target = threshold * k;
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < k; i += 1) { sum += arr[i]; }

    if (sum >= target) { cnt += 1; }

    for (int i = k; i < len; i += 1) {
        sum = sum + arr[i] - arr[i - k];

        if (sum >= target) { cnt += 1; }
    }

    return cnt;
}
