#define TOTAL (24 * 60)

inline static int calc_h_m(const char *restrict s) {
    const int h = ((int)s[0] - '0') * 10 + (int)s[1] - '0';
    const int m = ((int)s[3] - '0') * 10 + (int)s[4] - '0';

    return h * 60 + m;
}

int convertTime(const char *current, const char *correct) {
    const int m1 = calc_h_m(current);
    const int m2 = calc_h_m(correct);

    const int dm = (m2 + TOTAL - m1) % TOTAL;

    return dm / 60  + (dm % 60) / 15 + (dm % 15) / 5 + (dm % 5);
}
