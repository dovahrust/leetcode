struct tuple {
    uint32_t bits;
    int word_len;
    bool is_valid;
};

static int dfs(const int len, const int idx, const uint32_t seen, const struct tuple* valids)
{
    if (idx >= len) {
        return 0;
    }

    const uint32_t bits = valids[idx].bits;
    const bool is_valid = valids[idx].is_valid;
    int keep = 0;
    if (is_valid && (seen & bits) == 0) {
        keep = valids[idx].word_len + dfs(len, idx + 1, seen | bits, valids);
    }

    const int skip = dfs(len, idx + 1, seen, valids);

    return skip > keep ? skip : keep;
}

int maxLength(char** arr, const int len)
{
    assert(len >= 1 && len <= 16 && arr != NULL);
    struct tuple* valids = malloc((size_t)len * sizeof(*valids));

    for (int i = 0; i < len; i += 1) {
        char* a = arr[i];
        const size_t word_len = strlen(a);
        assert(word_len <= 26);
        uint32_t bits = 0;
        bool is_valid = true;
        for (size_t j = 0; j < word_len; j += 1) {
            const char ch = a[j];
            assert(ch >= 'a' && ch <= 'z');
            const uint32_t mask = 1u << (ch - 'a');
            if ((mask & bits) != 0) {
                is_valid = false;
                break;
            }
            bits |= mask;
        }
        valids[i] = (struct tuple){ .bits = bits, .is_valid = is_valid, .word_len = (int)word_len };
    }

    const uint32_t seen = 0;
    const int res = dfs(len, 0, seen, valids);

/* cleanup: */
    free(valids);
    return res;
}
