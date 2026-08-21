typedef struct {
    int valids_len;
    int m;
    int n;
    int valids[];
} Solution;

Solution* solutionCreate(int m, int n) {
    assert(n >= 1 && m >= 1 && n <= 10000 && m <= 10000);
    const int total = n * m;
    Solution* res = malloc(sizeof(*res) + (size_t)total * sizeof(int));
    if (res == NULL) { return NULL; }

    for (int i = 0; i < total; i += 1) {
        res->valids[i] = i;
    }
    res->valids_len = total;
    res->n = n;
    res->m = m;

    return res;
}

int* solutionFlip(Solution* obj, int* return_len) {
    assert(return_len != NULL && obj != NULL);
    if (obj->valids_len == 0) {
        *return_len = 0;
        return NULL;
    }

    int *ret_vec = malloc(2 * sizeof(*ret_vec));
    if (ret_vec == NULL) {
        *return_len = 0;
        return NULL;
    }

    const int random_value = (int)(random() % obj->valids_len);
    const int res = obj->valids[random_value];
    obj->valids[random_value] = obj->valids[obj->valids_len - 1];
    obj->valids[obj->valids_len - 1] = res;

    obj->valids_len -= 1;
    *return_len = 2;
    ret_vec[0] = res / obj->n;
    ret_vec[1] = res % obj->n;

    return ret_vec;
}

void solutionReset(Solution* obj) {
    const int total = obj->n * obj->m;
    obj->valids_len = total;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(m, n);
 * int* param_1 = solutionFlip(obj, retSize);

 * solutionReset(obj);

 * solutionFree(obj);
*/
