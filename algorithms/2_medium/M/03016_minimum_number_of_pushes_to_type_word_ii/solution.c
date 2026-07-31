#define FREQS_LEN 26

static inline int reduce_int(const int* begin, const int* end) {
    int res = 0;
    for (const int* it = begin; it != end; it += 1) {
        res += *it;
    }
    return res;
}

static int cmp(const void* a_ptr, const void* b_ptr) {
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;
    return (a < b) - (a > b);
}

int minimumPushes(char* word) {
    assert(word != NULL);
    int freqs[FREQS_LEN] = { 0 };

    for (char* it = word; *it != '\0'; it += 1) {
        assert(*it >= 'a' && *it <= 'z' && it - word <= INT_MAX);
        freqs[*it - 'a'] += 1;
    }

    qsort(freqs, FREQS_LEN, sizeof(*freqs), cmp);

    return reduce_int(freqs, freqs + 8) +
           reduce_int(freqs + 8, freqs + 16) * 2 +
           reduce_int(freqs + 16, freqs + 24) * 3 +
           reduce_int(freqs + 24, freqs + FREQS_LEN) * 4;
}
