bool isRectangleOverlap(const int *rec1, int rec1_len, const int *rec2, int rec2_len) {
    return MAX(rec1[0], rec2[0]) < MIN(rec1[2], rec2[2]) && MAX(rec1[1], rec2[1]) < MIN(rec1[3], rec2[3]);
}
