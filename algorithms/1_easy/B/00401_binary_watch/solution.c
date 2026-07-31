/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(const int turned_on, int* return_len) {
    char** res = NULL;
    size_t res_len = 0;
    size_t res_cap = 0;

    for (int h = 0; h <= 11; h += 1) {
        for (int m = 0; m <= 59; m += 1) {
            if (__builtin_popcount(h) + __builtin_popcount(m) == turned_on) {
                char* temp = NULL;
                if (m < 10) {
                    if (asprintf(&temp, "%d:0%d", h, m) == -1) {
                        fprintf(stderr, "alloc fail");
                        exit(1);
                    }
                } else {
                    if (asprintf(&temp, "%d:%d", h, m) == -1) {
                        fprintf(stderr, "alloc fail");
                        exit(1);
                    }
                }
                if (res_len == res_cap) {
                    res_cap = res_cap == 0 ? 4 : res_cap * 2;
                    res = realloc(res, res_cap * sizeof(char*));
                    if (res == NULL) {
                        fprintf(stderr, "alloc fail");
                        exit(1);
                    }
                }

                res[res_len] = temp;
                res_len += 1;
            }
        }
    }

    *return_len = (int)res_len;
    return res;
}
