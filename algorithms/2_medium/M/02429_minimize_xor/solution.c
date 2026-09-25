int minimizeXor(const int num1_int, const int num2_int) {
    assert(num1_int >= 1 && num2_int >= 1);
    const unsigned int num1 = (unsigned int)num1_int;
    const unsigned int num2 = (unsigned int)num2_int;
    size_t ones = __builtin_popcount(num2);
    unsigned int res = 0;

    for (int i = 31; i >= 0; i -= 1) {
        if (ones == 0) { break; }

        const unsigned int mask = (1u << (unsigned int)i);
        if ((mask & num1) != 0) {
            res |= mask;
            ones -= 1;
        }
    }

    for (unsigned int i = 0; i < 32; i += 1) {
        if (ones == 0) { break; }

        const unsigned int mask = (1u << i);
        if ((mask & num1) == 0) {
            res |= mask;
            ones -= 1;
        }
    }

    return (int)res;
}
