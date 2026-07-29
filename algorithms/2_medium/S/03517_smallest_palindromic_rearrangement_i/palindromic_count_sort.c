char* smallestPalindrome(char* s)
{
    assert(s != NULL && s[0] != '\0');
    size_t freqs[26] = { 0 };
    size_t i = 0;

    for (; s[i] != '\0'; i += 1) {
        assert(s[i] >= 'a' && s[i] <= 'z');
        freqs[s[i] - 'a'] += 1;
    }

    const size_t len = i;
    size_t lo = 0;
    size_t hi = i - 1;

    for (i = 0; i < 26; i += 1) {
        if ((freqs[i] & 1) == 1) {
            const size_t mid_index = len / 2;
            s[mid_index] = (char)(i + 'a');
        }

        const size_t steps = freqs[i] / 2;
        for (size_t step = 0; step < steps; step += 1) {
            s[lo] = (char)(i + 'a');
            s[hi] = (char)(i + 'a');
            lo += 1;
            hi -= 1;
        }
    }

    return s;
}
