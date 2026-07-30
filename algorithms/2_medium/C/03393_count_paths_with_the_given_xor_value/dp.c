#define MAX_NUM 15
#define MOD 1000000007

int countPathsWithXorValue(
    int** grid,
    const int rows,
    const int* cols_data,
    const int k
) {
    assert(rows > 0 && cols_data != NULL && cols_data[0] > 0 && k >= 0 && k <= MAX_NUM);

    const int cols = cols_data[0];
    int* buff = calloc((size_t)(2 * cols * (MAX_NUM + 1)), sizeof(*buff));
    assert(buff != NULL);
    int* prev = &buff[0];
    int* curr = &buff[(size_t)(cols * (MAX_NUM + 1))];

    int xor = 0;
    for (int j = 0; j < cols; j += 1) {
        const int v = grid[0][j];
        assert(v >= 0 && v <= MAX_NUM);
        xor ^= v;
        prev[j * (MAX_NUM + 1) + xor] = 1;
    }

    for (int i = 1; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            const int v = grid[i][j];
            assert(v >= 0 && v <= MAX_NUM);
            for (int prev_val = 0; prev_val <= MAX_NUM; prev_val += 1)  {
                const int curr_idx = j * (MAX_NUM + 1) + (prev_val ^ v);
                const int up_idx = j * (MAX_NUM + 1) + prev_val;

                curr[curr_idx] = prev[up_idx];
            }

            if (j > 0) {
                for (int prev_val = 0; prev_val <= MAX_NUM; prev_val += 1)  {
                    const int curr_idx = j * (MAX_NUM + 1) + (prev_val ^ v);
                    const int left_idx = (j - 1) * (MAX_NUM + 1) + prev_val;

                    curr[curr_idx] = (curr[curr_idx] + curr[left_idx]) % MOD;
                }
            }
        }

        int* temp = prev;
        prev = curr;
        curr = temp;
        for (int idx = 0; idx < cols * (MAX_NUM + 1); idx += 1) {
            curr[idx] = 0;
        }
    }

    const int target_idx = (cols - 1) * (MAX_NUM + 1) + k;
    const int res = prev[target_idx];

/* cleanup: */
    free(buff);
    return res;
}
