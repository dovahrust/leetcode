bool canReach(const int *start, int start_len, const int *target, int target_len) {
    return ((start[0] + start[1]) & 1) == ((target[0] + target[1]) & 1);
}
