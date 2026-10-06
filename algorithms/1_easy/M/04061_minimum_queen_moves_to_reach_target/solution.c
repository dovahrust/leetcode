int minQueenMoves(const int *source, const int source_len, const int *target, const int target_len) {
    const int si = source[0];
    const int sj = source[1];
    const int ti = target[0];
    const int tj = target[1];

    if (si == ti && sj == tj) { return 0; }

    if (si == ti || sj == tj) { return 1; }

    if (ABS(si - ti) == ABS(sj - tj)) { return 1; }

    return 2;
}
