enum state {
    NONE,
    HAS_KEY,
    HAS_BOX,
    VISITED,
};

int maxCandies(
    const int *restrict status, const int status_len, 
    const int *restrict candies, const int candiesSize,
    int *restrict *restrict keys, int keys_len, const int *restrict keys_cols_data,
    int *restrict *restrict contained_boxes, int contained_boxes_len, int *restrict contained_boxes_cols_data,
    const int *restrict initial_boxes, const int initial_boxes_len
) {
    const int n = status_len;
    assert(n <= 1000 && n >= 1);
    enum state* states = calloc((size_t)n, sizeof(*states));
    if (states == NULL) { return -1; }
    int *restrict stack = malloc((size_t)n * sizeof(*stack));
    if (stack == NULL) {
        free(states);
        return -1;
    }
    int cnt = 0;
    size_t stack_len = 0;

    for (int i = 0; i < n; i+= 1) {
        if (status[i] == 1) {
            states[i] = HAS_KEY;
        }
    }

    for (int ib_idx = 0; ib_idx < initial_boxes_len; ib_idx += 1) {
        const int i = initial_boxes[ib_idx];
        if (states[i] == HAS_KEY) {
            states[i] = VISITED;
            stack[stack_len] = i;
            stack_len += 1;
        } else {
            states[i] = HAS_BOX;
        }
    }

    while (stack_len > 0) {
        stack_len -= 1;
        const int i = stack[stack_len];
        cnt += candies[i];

        const int *restrict keys_to_scan = keys[i];
        const int keys_to_scan_len = keys_cols_data[i];
        for (int j = 0; j < keys_to_scan_len; j += 1) {
            const int key = keys_to_scan[j];
            if (states[key] == VISITED) {
                continue;
            } else if (states[key] == NONE || states[key] == HAS_KEY) {
                states[key] = HAS_KEY;
            } else {
                states[key] = VISITED;
                stack[stack_len] = key;
                stack_len += 1;
            }
        }

        const int *restrict boxes_to_scan = contained_boxes[i];
        const int boxes_to_scan_len = contained_boxes_cols_data[i];
        for (int j = 0; j < boxes_to_scan_len; j += 1) {
            const int box = boxes_to_scan[j];
            if (states[box] == VISITED) {
                continue;
            } else if (states[box] == NONE || states[box] == HAS_BOX) {
                states[box] = HAS_BOX;
            } else {
                states[box] = VISITED;
                stack[stack_len] = box;
                stack_len += 1;
            }
        }
    }

    free(stack);
    free(states);
    return cnt;
}
