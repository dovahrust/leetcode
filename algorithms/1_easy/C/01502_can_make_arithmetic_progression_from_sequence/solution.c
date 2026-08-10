static int cmp(const void* a_ptr, const void* b_ptr) {
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;
    return (a > b) - (a < b);
}

bool canMakeArithmeticProgression(int* arr, const int len) {
    if (len <= 2) { return true; }
    assert(arr != NULL);
    qsort(arr, (size_t)len, sizeof(int), cmp);
    const int diff = arr[1] - arr[0];

    for (int i = 2; i < len; i += 1) {
        if (arr[i] - arr[i - 1] != diff) {
            return false;
        }
    }

    return true;
}
