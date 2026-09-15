int shortestSequence(const int *restrict rolls, const int rolls_len, const int k) {
    int *restrict states = calloc((size_t)(k + 1), sizeof(*states));
    if (states == NULL) { return -1; }
    int state = 1;
    int seen_cnt = 0;

    for (int i = 0; i < rolls_len; i += 1)  {
        if (states[rolls[i]] != state) {
            seen_cnt += 1;
            states[rolls[i]] = state;

            if (seen_cnt == k) {
                state += 1;
                seen_cnt = 0;
            }
        }
    }

    free(states);
    return state;
}
