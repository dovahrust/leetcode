static inline int min_int(const int a, const int b) {
    return a < b ? a : b;
}

int minimumPushes(char* word) {
    assert(word != NULL && strlen(word) <= 26ULL);
    const int n = (int)strlen(word);

    return n + (n - min_int(n, 8)) + (n - min_int(n, 16)) +  (n - min_int(n, 24));
}
