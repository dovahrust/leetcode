#define MAX_NUM 50
#define MIN_NUM 1
#define MAX_LEN 50

int missingInteger(const int* nums, const int len) {
    if (nums == NULL || len > MAX_LEN || len <= 0) { goto input_err; }

    bool seen[MAX_NUM + 2] = { false };
    for (int i = 0; i < len; i += 1) {
        if (nums[i] < MIN_NUM || nums[i] > MAX_NUM) {
            goto input_err;
        }
        seen[nums[i]] = true;
    }

    int prefix = nums[0];
    int i = 1;
    while (i < len && nums[i] == nums[i - 1] + 1) {
        prefix += nums[i];
        i += 1;
    }

    if (prefix > MAX_NUM) {
        return prefix;
    }

    for (int i = prefix; i < MAX_NUM + 2; i += 1) {
        if (!seen[i]) {
            return i;
        }
    }

    fprintf(stderr, "unreachable!()");
    exit(1);

input_err:
    fprintf(stderr, "invalid input");
    return -1;
}
