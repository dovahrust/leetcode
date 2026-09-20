int addRungs(const int *restrict rungs, const int len, const int dist) {
    int curr = 0;
    int cnt = 0;
    for (int i = 0; i < len; i += 1) {
        const int next = rungs[i];
        const int width = next - curr;
        cnt += (width - 1) / dist;
        curr = next;
    }
    return cnt;
}
