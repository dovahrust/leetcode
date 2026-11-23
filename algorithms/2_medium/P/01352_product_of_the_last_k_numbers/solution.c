#define MAX_CALLS 40000

typedef struct {
    int nums[MAX_CALLS];
    size_t len;
} ProductOfNumbers;


ProductOfNumbers *productOfNumbersCreate() {
    ProductOfNumbers *res = malloc(sizeof(*res));
    assert(res != NULL);
    res->len = 0;
    return res;
}

void productOfNumbersAdd(ProductOfNumbers* obj, const int num) {
    if (num == 0) {
        obj->len = 0;;
    } else {
        assert(obj->len < MAX_CALLS);
        const int last = obj->len ==  0 ? 1 : obj->nums[obj->len - 1];
        obj->nums[obj->len] = last * num;
        obj->len += 1;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, const int k) {
    assert(k >= 1);
    if ((size_t)k > obj->len) { return 0; }

    const int last = obj->nums[obj->len - 1];
    const int before_k = ((size_t)k == obj->len) ? 1 : obj->nums[obj->len - (size_t)k - 1];

    return last / before_k;
}

void productOfNumbersFree(ProductOfNumbers *obj) {
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
