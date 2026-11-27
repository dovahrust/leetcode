static int calc_max_factor(int **items, const int items_len) {
    int res = INT_MIN;
    for (int i = 0; i < items_len; i += 1) {
        assert(items[i][0] >= 1 && items[i][0] <= 1500);
        res = MAX(res, items[i][0]);
    }
    return res;
}

int maximumSaleItems(int **items, const int items_len, const int *items_cols_len, const int budget) {

    assert(budget >= 1 && budget<= 1500 && items_len > 0 &&
           items != NULL && items_cols_len != NULL && items_cols_len[0] == 2);

    const int max_factor = calc_max_factor(items, items_len);
    int *restrict buff = calloc((size_t)(max_factor + 1 + budget + 1), sizeof(*buff));
    int *restrict cnts = &buff[0];
    int *restrict dp = &buff[1 + max_factor];

    for (int i = 0; i < items_len; i += 1) { cnts[items[i][0]] += 1; }

    for (int i = 1; i <= max_factor; i += 1) {
        int sum = 0;
        for (int j = i; j <= max_factor; j += i) {
            sum += cnts[j];
        }
        cnts[i] = sum;
    }

    for (int i = 0; i < items_len; i += 1) {
        const int price = items[i][1];
        const int factor =  items[i][0];
        if (price > budget) {  continue; }

        for (int j = price; j <= budget; j += 1) { dp[j] = MAX(dp[j], dp[j - price] + 1); }

        const int cnt = cnts[factor];

        if (cnt == 1) { continue; }

        for (int j = budget; j  >= price; j -= 1) { dp[j] = MAX(dp[j], dp[j - price] + cnt); }
    }

/* cleanup: */
    const int res = dp[budget];
    free(buff);
    return res;
}
