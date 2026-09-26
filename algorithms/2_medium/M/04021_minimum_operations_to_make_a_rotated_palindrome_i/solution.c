typedef ptrdiff_t isize;

int minOperations(const char *restrict s) {
    const isize len = (isize)strlen(s);
    isize min = PTRDIFF_MAX;

    for (isize i = 0; i < len; i += 1) {
        isize lo = i;
        isize hi = i == 0 ? (len - 1) : (i - 1);
        isize score = 0;

        while (true) {
            const isize diff = ABS((isize)s[lo] - (isize)s[hi]);
            score += MIN(diff, 26 - diff);

            hi = hi - 1 == -1 ? (len - 1) : (hi - 1);

            if (hi == lo) { break; }

            lo = lo + 1 == len ? 0 : (lo + 1);

            if (hi == lo) { break; }
        }

        min = MIN(min, score + i);
    }

    return (int)min;
}
