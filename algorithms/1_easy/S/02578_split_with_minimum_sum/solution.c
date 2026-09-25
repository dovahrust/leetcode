int splitNum(int num) {
    int freqs[10] = { 0 };

    while (num > 0) {
        freqs[num % 10] += 1;
        num /= 10;
    }

    int n1 = 0;
    int n2 = 0;

    for (int i = 1; i < 10; i += 1) {
        while (freqs[i] > 0) {
            if (n1 < n2) {
                n1 = (n1 * 10) + i;
            } else {
                n2 = (n2 * 10) + i;
            }

            freqs[i] -= 1;
        }
    }

    return n1 + n2;
}
