static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

char* stoneGameIII(const int* stone_value, const int len) {
    if (len < 0 || (len > 0 && stone_value == NULL)) {
        fprintf(stderr, "invalid input");
        exit(1);
    }
    int next1 = 0;
    int next2 = 0;
    int next3 = 0;

    for (int i = len - 1; i >= 0; i -= 1) {
        int curr = stone_value[i] - next1;
        if (i + 1 < len) {
            curr = max_int(curr, stone_value[i] + stone_value[i + 1] - next2);
        }
        if (i + 2 < len) {
            curr = max_int(curr, stone_value[i] + stone_value[i + 1] + stone_value[i + 2] - next3);
        }
        next3 = next2;
        next2 = next1;
        next1 = curr;
    }

    if (next1 < 0) {
        return strdup("Bob");
    } else if (next1 == 0) {
        return strdup("Tie");
    } else {
        return strdup("Alice");
    }
}
