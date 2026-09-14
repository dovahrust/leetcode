int elevatorRequests(const int n, const int *restrict requests, const int len) {
    int prev = 0;
    int res = 0;

    for (int i = 0; i < len; i += 1) {
        res += ABS(prev - requests[i]);
        prev = requests[i];
    }

    return res;
}
