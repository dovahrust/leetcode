#define INVALID PTRDIFF_MIN

typedef ptrdiff_t isize;

inline static size_t get_mask_char(const char ch) {
    switch (ch) {
        case 'a': return 1;
        case 'e': return (1 << 1);
        case 'i': return (1 << 2);
        case 'o': return (1 << 3);
        case 'u': return (1 << 4);
        default: return 0;
    }
}

int findTheLongestSubstring(const char *restrict s) {
    isize first_seen[32];
    for (isize i = 0; i < 32; i += 1) { first_seen[i] = INVALID; }
    first_seen[0] = -1;
    size_t curr_state = 0;
    isize longest = 0;

    for (isize i = 0; s[i] != '\0'; i += 1) {
        const size_t mask = get_mask_char(s[i]);
        curr_state ^= mask;
        if (first_seen[curr_state] != INVALID) {
            longest = MAX(longest, i - first_seen[curr_state]);
        } else {
            first_seen[curr_state] = i;
        }
    }

    return (int)longest;
}
