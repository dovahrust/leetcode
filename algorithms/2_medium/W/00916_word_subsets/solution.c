#define FREQS_LEN 26

static inline uint8_t max_u8(const uint8_t a, const uint8_t b)
{
    return a > b ? a : b;
}

static inline void calc_freqs(const char* s, uint8_t* res)
{
    for (size_t i = 0; s[i] != '\0'; i += 1) {
        const char ch = s[i];
        assert(ch >= 'a' && ch <= 'z' && res[ch - 'a'] < UINT8_MAX);
        res[ch - 'a'] += 1;
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordSubsets(char** words1, int len1, char** words2, const int len2, int* return_len)
{
    assert(len1 > 0 && len2 > 0 && return_len != NULL && words1 != NULL && words2 != NULL);
    char** res = NULL;
    size_t res_cap = 0;
    size_t res_len = 0;
    uint8_t max_freqs2[FREQS_LEN] = { 0 };
    for (int i = 0; i < len2; i += 1) {
        uint8_t freqs[FREQS_LEN] = { 0 };
        calc_freqs(words2[i], freqs);
        for (int i = 0; i < FREQS_LEN; i += 1) {
            max_freqs2[i] = max_u8(max_freqs2[i], freqs[i]);
        }
    }

    for (int i = 0; i < len1; i += 1) {
        uint8_t freqs[FREQS_LEN] = { 0 };
        calc_freqs(words1[i], freqs);
        bool is_valid = true;

        for (int i = 0; i < FREQS_LEN; i += 1) {
            if (max_freqs2[i] > freqs[i]) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            if (res_cap == res_len) {
                res_cap = res_cap == 0 ? 4 : 2 * res_cap;
                res = realloc(res, res_cap * sizeof(*res));
                assert(res != NULL);
            }
            res[res_len] = strdup(words1[i]);
            assert(res[res_len] != NULL);
            res_len += 1;
        }
    }

    assert(res_len <= (size_t)INT_MAX);
    *return_len = (int)res_len;
    return res;
}
