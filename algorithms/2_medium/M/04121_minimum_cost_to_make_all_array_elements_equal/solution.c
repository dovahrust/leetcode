long long minCost(const int *restrict nums, const int len) {
    int i = 0;
    int64_t cost = INT64_MAX;

    while (i < len) {
        int j = i;
        while (j + 1 < len && nums[j + 1] == nums[i]) { j += 1; }

        const int64_t cost_pref = (int64_t)i * nums[i];
        const int64_t cost_suff = (int64_t)(len - j - 1) * nums[i];

        if (j != 0 && i != len - 1) { cost = MIN(cost, cost_pref + cost_suff); }

        i = j + 1;
    }

    return cost;
}
