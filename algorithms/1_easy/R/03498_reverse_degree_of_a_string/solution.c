typedef ptrdiff_t isize;

int reverseDegree(const char *restrict s) {
    isize sum = 0;
    for(isize i = 0; s[i] != '\0'; i += 1) {
        sum += (isize)(unsigned char)('z'- s[i] + 1) * (i + 1);
    }
    return (int)sum;
}
