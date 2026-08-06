static inline int calc_product_digits(int n) {
    int res = 1;

    while (n > 0) {
        res = res * (n % 10);
        n /= 10;
    }

    return res;
}

int smallestNumber(const int n, const int t) {
    // In every 10 consecutive numbers, at least one has the digit 0,
    // ensuring a product of 0, which satisfies the condition 0 % t == 0.
    for (int i = n; i < n + 10; i += 1) {
        const int product_digits = calc_product_digits(i);

        if (product_digits % t == 0) {
            return i;
        }
    }

    fprintf(stderr, "unreachable!() - logic error");
    exit(1);
}
