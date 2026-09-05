bool checkPerfectNumber(const int num) {
    if (num <= 1) { return false; }

    int sum = 1;
    const int sq = (int)sqrt(num);

    for (int i = 2; i <= sq; i += 1) {
        if (num % i == 0) {
            sum += i;

            const int other = num / i;
            if (i != other) {
                sum += other;
            }

            if (sum > num) {
                return false;
            }
        }
    }

    return sum == num;
}
