bool checkOverlap(int r, int cx, int cy, int rx1, int ry1, int rx2, int ry2) {
    const int closest_x = MAX(rx1, MIN(rx2, cx));
    const int closest_y = MAX(ry1, MIN(ry2, cy));

    const int dx = cx - closest_x;
    const int dy = cy - closest_y;

    return (dx * dx) + (dy * dy) <= r * r;
}
