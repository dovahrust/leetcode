int countVowelStrings(const int n) {
    if (n < 1 || n > 50) { return -1; }

    int buff[10] = { 0 };
    int *restrict prev = &buff[0];
    for (int i = 0; i < 5; i += 1) { prev[i] = 1; }
    int *restrict curr = &buff[5];

    for (int steps = 1; steps < n; steps += 1) {
        for (int i = 0; i < 5; i += 1) { 
            curr[i] = 0;
        }

        for (int i = 0; i < 5; i += 1) {
            for (int j = 0; j <= i; j += 1) {
                curr[j] += prev[i];
            }
        }

        void *temp = prev;
        prev = curr;
        curr = temp;
    }

    int sum = 0;
    for (int i = 0; i < 5; i += 1) {
        sum += prev[i];
    }

    return sum;
}
