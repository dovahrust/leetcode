bool checkTwoChessboards(const char *c1, const char *c2) {
    return (((c1[0] - '0') + (c1[1] - 'a')) & 1) == (((c2[0] - '0') + (c2[1] - 'a')) & 1);
}
