#define MAX_ALLOWED_FREQ 10

static size_t calc_freqs_smallest_char(const char* s)
{
    assert(s != NULL);
    char curr_ch = 'z';
    size_t freq = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        if (s[i] < curr_ch) {
            curr_ch = s[i];
            freq = 1;
        } else if (s[i] == curr_ch) {
            freq += 1;
        }
    }

    return freq;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numSmallerByFrequency(char** queries, const int queries_len,
                           char** words, const int words_len, int* return_len)
{
    assert(queries_len > 0 && words_len > 0 && return_len != NULL && queries != NULL && words != NULL);
    assert(words_len <= 2000 && queries_len <= 2000);


    int16_t prefix[MAX_ALLOWED_FREQ + 1] = { 0 };
    for (int i = 0; i < words_len; i += 1) {
        const size_t freq = calc_freqs_smallest_char(words[i]);
        assert(freq <= MAX_ALLOWED_FREQ);
        prefix[freq] += 1;
    }
    for (size_t i = 1; i <= MAX_ALLOWED_FREQ; i += 1) {
        prefix[i] += prefix[i - 1];
    }

    int* res = malloc((size_t)queries_len * sizeof(*res));
    assert(res != NULL);
    *return_len = queries_len;

    for (int i = 0; i < queries_len; i += 1) {
        const size_t freq = calc_freqs_smallest_char(queries[i]);
        if (freq >= MAX_ALLOWED_FREQ) {
            res[i] = 0;
        } else {
            res[i] = prefix[MAX_ALLOWED_FREQ] - prefix[freq];
        }
    }

    return res;
}
