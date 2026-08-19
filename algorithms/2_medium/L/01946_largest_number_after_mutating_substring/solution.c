#define CHANGE_LEN 10

 __attribute__((no_sanitize("all")))
static inline bool can_improve_by_change(const int *restrict change_vec) {
    for (int i = 0; i < CHANGE_LEN; i += 1) {
        if (i < change_vec[i]) {
            return true;
        }
    }
    return false;
}

 __attribute__((no_sanitize("all")))
char* maximumNumber(char *restrict num, const int *restrict change_vec, const int change_vec_len) {
    if (change_vec_len != CHANGE_LEN || num == NULL || change_vec == NULL) { return NULL; }

    if (!can_improve_by_change(change_vec)) {
        return num;
    }

    char change[CHANGE_LEN];
    for (int i = 0; i < CHANGE_LEN; i += 1) {
        const int x = change_vec[i];
        if (x < 0 || x > 9) { return NULL; }
        change[i] = (char)('0' + change_vec[i]);
    }

    bool has_changed = false;
    for (size_t i = 0; num[i] != '\0'; i += 1) {
        if (num[i] < '0' || num[i] > '9') { return NULL; }

        const int idx = num[i] - '0';
        if (num[i] < change[idx]) {
            num[i] = change[idx];
            has_changed = true;
        } else if (has_changed && num[i] != change[idx]) {
            break;
        }
    }

    return num;
}
