bool checkDivisibility(const int n) {
    int temp = n;
    int d_sum = 0;
    int d_mul = 1;

    while (temp > 0) {
        const int digit = temp % 10;
        d_sum += digit;
        d_mul *= digit;
        temp /= 10;
    }

    return n % (d_sum + d_mul) == 0;
}
