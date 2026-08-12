struct entity {
    int sum;
    int idx;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(const int *restrict nums, const int len, const int k, int *restrict return_len) {
    if (k < 1 || k > len / 3 || len > 20000 || nums == NULL || return_len == NULL) {
        goto err;
    }
    int *restrict prefix_sum = malloc((size_t)(len + 1) * sizeof(*prefix_sum));
    if (prefix_sum == NULL) {
        goto err;
    }
    prefix_sum[0] = 0;
    for (int i = 0; i < len; i += 1) {
        if (nums[i] < 1 || nums[i] >= (1 << 16)) {
            exit(1);
        }
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    struct entity *restrict buff = calloc((size_t)(len + 1) * 2, sizeof(*buff));
    if (buff == NULL) {
        goto err_clean_prefix;
    }
    struct entity *restrict prefix_max = &buff[0];
    struct entity *restrict suffix_max = &buff[len + 1];

    for (int i = 0; i <= len - k; i += 1) {
        const int curr = prefix_sum[i + k] - prefix_sum[i];
        if (i == 0 || curr > prefix_max[i - 1].sum) {
            prefix_max[i] = (struct entity){ .sum = curr, .idx = i };
        } else {
            prefix_max[i] = prefix_max[i - 1];
        }
    }

    for (int i = len - k; i >= 0; i -= 1) {
        const int curr = prefix_sum[i + k] - prefix_sum[i];
        if (curr >= suffix_max[i + 1].sum) {
            suffix_max[i] = (struct entity){ .sum = curr, .idx = i };
        } else {
            suffix_max[i] = suffix_max[i + 1];
        }
    }

    int sum = 0;
    int* res = calloc(3, sizeof(*res));
    if (res == NULL) {
        goto err_clean_buff;
    }

    for (int i = k; i <= len - k - k; i += 1) {
        const int curr_sum = prefix_sum[i + k] - prefix_sum[i] +
                             prefix_max[i - k].sum + 
                             suffix_max[i + k].sum;

        if (curr_sum > sum) {
            sum = curr_sum;
            res[0] = prefix_max[i - k].idx;
            res[1] = i;
            res[2] = suffix_max[i + k].idx;
        }
    }

    *return_len = 3;
    free(buff);
    free(prefix_sum);
    return res;

err_clean_buff:
    free(buff);
err_clean_prefix:
    free(prefix_sum);
err:
    *return_len = 0;
    return NULL;
}
