typedef struct {
    int len;
    int prefix[];
} Solution;


Solution* solutionCreate(const int* w, const int len) {
    if (len <= 0 || w == NULL || len > 10000) {
        goto invalid_input;
    }

    Solution* obj = malloc(sizeof(*obj) + (size_t)len * sizeof(int));
    if (obj == NULL) {
        goto alloc_fail;
    }
    obj->prefix[0] = w[0];
    for (int i = 1; i < len; i += 1) {
        if (w[i] < 1 || w[i] > 100000) {
            goto invalid_input_clean;
        }
        obj->prefix[i] = obj->prefix[i - 1] + w[i];
    }

    obj->len = len;
    return obj;

invalid_input_clean:
    free(obj);
invalid_input:
    fprintf(stderr, "invalid input");
    return NULL;

alloc_fail:
    fprintf(stderr, "alloc fail");
    return NULL;
}

int solutionPickIndex(const Solution* obj) {
    if (obj == NULL) { return -1; }
    const int max = obj->prefix[obj->len - 1];
    const int random_value = (rand() % max) + 1;
    int lo = 0;
    int hi = obj->len - 1;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (random_value <= obj->prefix[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/
