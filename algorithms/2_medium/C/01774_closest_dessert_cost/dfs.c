inline static bool is_curr_better(const int curr, const int target, const int res) {
    return ABS(curr - target) < ABS(res - target) ||
           (ABS(curr - target) == ABS(res - target) && curr < res);
}

static void dfs(
    const int *restrict costs, const int len, const int idx,
    const int curr,
    const int target,
    int *res
) {
    if (is_curr_better(curr, target, *res)) {
        *res= curr;
    } else if (curr > target) {
        return;
    }

    if (idx == len) {
        return;
    }

    dfs(costs, len, idx + 1, curr, target, res);
    dfs(costs, len, idx + 1, curr + costs[idx], target, res);
    dfs(costs, len, idx + 1, curr + (2 * costs[idx]), target, res);
}

int closestCost(
    const int *base_costs, const int base_costs_len,
    const int *topping_costs, const int topping_costs_len,
    const int target
) {
    int res = INT_MAX;

    for (int i = 0; i < base_costs_len; i += 1) {
        dfs(topping_costs, topping_costs_len, 0, base_costs[i], target, &res);
    }

    return res;
}
