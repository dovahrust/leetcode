static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;

    return (a < b) - (a > b);
}

double minPrice(int *prices, int prices_len, int *discounts, int discounts_len) {
    const int min_len = MIN(prices_len, discounts_len);
    qsort(prices, (size_t)prices_len, sizeof(*prices), cmp);
    qsort(discounts, (size_t)discounts_len, sizeof(*discounts), cmp);
    double res = 0.0;

    for (int i = 0; i < min_len; i += 1) {
        res += (double)prices[i] * (100 - discounts[i]) / 100;
    }

    for (int i = min_len; i < prices_len; i += 1) {
        res += (double)prices[i];
    }

    return res;
}
