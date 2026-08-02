/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countTasks(const int* tasks, const int tasks_len, const int* shifts, const int shifts_len, int* return_len) {
    if (
        tasks_len < 1 || tasks_len > 100000 || tasks == NULL ||
        shifts == NULL || shifts_len < 0 || return_len == NULL
    ) {
        fprintf(stderr, "invalid input");
        goto err;
    }

    int* res = malloc((size_t)shifts_len * sizeof(*res));
    int64_t* prefix = malloc((size_t)(tasks_len + 1) * sizeof(*prefix));
    if (prefix == NULL || res == NULL) {
        fprintf(stderr, "alloc fail");
        goto cleanup_err;
    }
    prefix[0] = 0;
    for (int i = 0; i < tasks_len; i += 1) {
        const int t= tasks[i];
        if (t <= 0) {
            fprintf(stderr, "tasks should be positive");
            goto cleanup_err;
        }
        prefix[i + 1] = prefix[i] + t;
    }

    const int64_t sum_tasks = prefix[tasks_len];
    int64_t curr = 0;
    for (int i = 0; i < shifts_len; i += 1) {
        const int shift = shifts[i];
        if (shift <= 0) {
            fprintf(stderr, "shifts should be positive");
            goto cleanup_err;
        }
        curr += shift;

        if (curr >= sum_tasks) {
            curr = 0;
            res[i] = 0;
        } else {
            int lo = 0;
            int hi = tasks_len;

            while (lo <= hi) {
                const int mid = lo + (hi - lo) / 2;

                if (prefix[mid] <= curr) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            res[i] = tasks_len - hi;
        }
    }

/* cleanup_ok: */
    free(prefix);
    *return_len = shifts_len;
    return res;

cleanup_err:
    free(res);
    free(prefix);
err:
    *return_len = -1;
    return NULL;
}
