static bool dfs(
    const int* nums,
    const int lo,
    const int hi,
    const bool p1_turn,
    const int balance
) {
    if (lo > hi) {
        return balance >= 0;
    }

    if (p1_turn) {
        return dfs(nums, lo + 1, hi, !p1_turn, balance + nums[lo]) ||
               dfs(nums, lo, hi - 1, !p1_turn, balance + nums[hi]);
    } else {
        return dfs(nums, lo + 1, hi, !p1_turn, balance - nums[lo]) &&
               dfs(nums, lo, hi - 1, !p1_turn, balance - nums[hi]);
    }
}

bool predictTheWinner(const int* nums, const int len) {
    assert(len <= 20 && len >= 1 && nums != NULL);
    return dfs(nums, 0, len - 1, true, 0);
}
