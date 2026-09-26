char slowestKey(const int *restrict release_times, const int release_times_len, const char *restrict keys_pressed) {
    int prev = 0;
    int duration[256] = { 0 };
    for (int i = 0; i < release_times_len; i += 1) {
        duration[(unsigned char)keys_pressed[i]] =  MAX(duration[(unsigned char)keys_pressed[i]], release_times[i] - prev);
        prev = release_times[i];
    }

    int longest = 0;
    char longest_char = 0;
    for (int i = 0; i < 255; i += 1) {
        if (duration[i] >= longest) {
            longest = duration[i];
            longest_char = (char)i;
        }
    }

    return longest_char;
}
