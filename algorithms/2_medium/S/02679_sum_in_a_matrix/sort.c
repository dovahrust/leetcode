static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static int cmp(const void* a_ptr, const void* b_ptr)
{
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;
    return (a > b) - (a < b);
}

int matrixSum(int** nums, const int rows, const int* cols_data)
{
    assert(rows > 0 && nums != NULL && cols_data != NULL && cols_data[0] > 0);
    const int cols = cols_data[0];
    int score = 0;

    for (int i = 0; i < rows; i += 1) {
        qsort(nums[i], (size_t)cols, sizeof(**nums), cmp);
    }

    for (int j = 0; j < cols; j += 1) {
        int max = INT_MIN;

        for (int i = 0; i < rows; i += 1) {
            max = max_int(max, nums[i][j]);
        }

        score += max;
    }

    return score;
}
