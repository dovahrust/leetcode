typedef ptrdiff_t isize;

bool sumGame(const char *restrict num) {
    assert(num != NULL);
    const size_t len = strlen(num);
    assert((len & 1) == 0 && len >= 2);
    const size_t half = len / 2;
    isize balance_sum = 0;
    isize balance_cnt = 0;

    for (size_t i = 0; i < half; i += 1) {
        switch (num[i]) {
            case '?':
                balance_cnt += 1;
                break;
            default:
                balance_sum += num[i] - '0';
                break;
        }

        switch (num[i + half]) {
            case '?':
                balance_cnt -= 1;
                break;
            default:
                balance_sum -= num[i + half] - '0';
                break;
        }
    }

    if (balance_cnt == 0) {
        return balance_sum != 0;
    }

    if ((balance_cnt & 1) == 1 || balance_cnt * balance_sum >= 0 || (ABS(balance_sum) % 9) != 0) {
        return true;
    }

    return (ABS(balance_sum) / 9) != (ABS(balance_cnt) / 2);
}
