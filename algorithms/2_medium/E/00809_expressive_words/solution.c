inline static bool is_sub(const char *s, const size_t s_len, const char *t) {
    if (t == NULL) { return false; }

    const size_t t_len = strlen(t);
    size_t s_idx = 0;
    size_t t_idx = 0;

    while (s_idx < s_len && t_idx < t_len) {
        if (s_len - s_idx < t_len - t_idx || s[s_idx] != t[t_idx]) { return false; }

        const char ch = s[s_idx];
        const size_t s_begin = s_idx;
        const size_t t_begin = t_idx;

        while (s_idx < s_len && s[s_idx] == ch) {
            s_idx += 1;
        }

        while (t_idx < t_len && t[t_idx] == ch) {
            t_idx += 1;
        }

        const size_t s_cnt = s_idx - s_begin;
        const size_t t_cnt = t_idx - t_begin;

        if (s_cnt != t_cnt && (s_cnt < t_cnt || s_cnt == 2)) {
            return false;
        } 
    }

    return s_idx == s_len && t_idx == t_len;
}

int expressiveWords(const char *s, char** words, const int words_len) {
    if (s == NULL || s[0] == '\0' || words == NULL || words_len <= 0) { return -1; }

    int cnt = 0;
    const size_t s_len = strlen(s);

    for (int i = 0; i < words_len; i += 1) {
        if (is_sub(s, s_len, words[i])) {
            cnt += 1;
        }
    }

    return cnt;
}
