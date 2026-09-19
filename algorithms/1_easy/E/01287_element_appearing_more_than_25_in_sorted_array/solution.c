int findSpecialInteger(const int *restrict arr, const int len) {
    const int target_cnt = len / 4;
    int cnt = 0;
    int curr = 0;

    for (int i = 0; i < len; i += 1) {
        if (curr != arr[i]) {
            curr = arr[i];
            cnt = 1;
        } else {
            cnt += 1;
        }

        if (cnt > target_cnt) {
            return curr;
        }
    }

    perror("invvalid input");
    exit(1);
}
