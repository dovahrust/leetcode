#define HAMSTER 'H'
#define EMPTY '.'

int minimumBuckets(const char *restrict hamsters) {
    const size_t len = strlen(hamsters);
    size_t i = 0;
    size_t cnt = 0;

    while (i < len) {
        if (hamsters[i] == HAMSTER) {
            if (i + 1 < len && hamsters[i + 1] == EMPTY) {
                i += 3;
                cnt += 1;
            } else if (i > 0 && hamsters[i - 1] == EMPTY) {
                cnt += 1;
                i += 1;
            } else {
                return -1;
            }
        } else {
            i += 1;
        }
    }

    return (int)cnt;
}
