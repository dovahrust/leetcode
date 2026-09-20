int minElements(const int *restrict nums, const int len, const int limit, const int goal) {
    int64_t sum = 0;
    for (int i = 0; i < len; i += 1) {
        sum += nums[i];
    }
    const int64_t diff = ABS((int64_t)goal - sum);

    return (int)((diff + limit - 1) / limit);
}
