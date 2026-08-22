static bool dfs(const int width, const int k) {
    if (width == 1) { return false; }

    const int parent_width = width / 2;
    const int mid = parent_width + 1;

    if (k == mid) {
        return true;
    } else if (k < mid) {
        return dfs(parent_width, k);
    } else {
        return !dfs(parent_width, parent_width - (k - mid - 1));
    }
}

char findKthBit(int n, int k) {
    assert(n >= 1 && n <= 20);
    const int width = (1 << n) - 1;
    assert(k >= 1 && k <= width);

    if (dfs(width, k)) {
        return '1';
    } else {
        return '0';
    }
}
