int findClosest(const int x, const int y, const int z) {
    const int dx = ABS(z - x);
    const int dy = ABS(z - y);

    if (dx < dy) {
        return 1;
    } else if (dx > dy) {
        return 2;
    } else {
        return 0;
    }
}
