int maxConsecutiveAnswers(const char *restrict s, const int k_int) {
    if (k_int < 1 || s == NULL) { goto invalid_input; }
    const size_t k = (size_t)k_int;
    size_t cnt_true = 0;
    size_t cnt_false = 0;
    size_t lo = 0;
    size_t max = 0;

    for (size_t hi = 0; s[hi] != '\0'; hi += 1) {
        if (s[hi] == 'T') {
            cnt_true += 1;
        } else if (s[hi] == 'F') {
            cnt_false += 1;
        } else {
            goto invalid_input;
        }

        while (cnt_false > k && cnt_true > k) {
            if (s[lo] == 'T') {
                cnt_true -= 1;
            } else {
                cnt_false -= 1;
            }

            lo += 1;
        }

        max = MAX(max, cnt_true + cnt_false);
    }

    return (int)max;

invalid_input:
    fprintf(stderr, "invalid input");
    return -1;
}
