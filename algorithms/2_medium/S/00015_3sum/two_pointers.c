static inline int abs_int(const int a)
{
    return a < 0 ? -a : a;
}

static int custom_cmp(const void* a, const void* b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib); 
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, const int len, int* return_len, int** return_cols_len)
{
    assert(len >= 3 && len <= 3000 && nums != NULL && return_len != NULL && return_cols_len != NULL);
    qsort(nums, len, sizeof(*nums), custom_cmp);

    int** res = NULL;
    size_t res_len = 0;
    size_t res_cap = 0;

    if (nums[len - 1] < 0) {
        *return_len = 0;
        return res;
    }

    for (int lo = 0; lo < len - 2; lo += 1) {
        if (nums[lo] > 0) {
            break;
        }

        if (lo > 0 && (nums[lo] == nums[lo - 1] || abs_int(nums[lo]) > nums[len - 1] * 2)) {
            continue;
        }

        int hi = len - 1;
        int mid = lo + 1;

        while (mid < hi) {
            const int sum = nums[lo] + nums[mid] + nums[hi];

            if (sum < 0) {
                mid += 1;
            } else if (sum > 0) {
                hi -= 1;
            } else {
                if (res_len == res_cap) {
                    res_cap = res_cap == 0 ? 4 : 2 * res_cap;
                    res = realloc(res, res_cap * sizeof(*res));
                    assert(res != NULL);
                }
                res[res_len] = malloc(3 * sizeof(**res));
                assert(res[res_len] != NULL);
                res[res_len][0] = nums[lo];
                res[res_len][1] = nums[mid];
                res[res_len][2] = nums[hi];
                res_len += 1;

                while (true) {
                    mid += 1;

                    if (mid >= hi || nums[mid] != nums[mid - 1]) {
                        break;
                    }
                }
            }
        }
    }

    assert(res_len <= (size_t)INT_MAX);
    *return_len = (int)res_len;
    int* cols_data = malloc(res_len * sizeof(*cols_data));
    assert(cols_data != NULL);
    for (size_t i = 0; i < res_len; i += 1) {
        cols_data[i] = 3;
    }
    *return_cols_len = cols_data;
    return res;
}
