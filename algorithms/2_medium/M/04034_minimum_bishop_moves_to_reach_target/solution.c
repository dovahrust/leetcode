int minBishopMoves(const int *source, const int source_len, const int *target, const int target_len) {
    const int sx = source[0];
    const int sy = source[1];
    const int tx = target[0];
    const int ty = target[1];

    if (sx == tx && sy == ty) {
        return 0;
    }

    if (((sx + sy) & 1) != ((tx + ty) & 1)) {
        return -1;
    }

    if (ABS(tx - sx) == ABS(ty - sy)) {
        return 1;
    }

    return 2;
}
