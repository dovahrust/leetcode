bool canThreePartsEqualSum(const int *restrict arr, const int len) {
    if (len < 3 || arr == NULL) {
        return false;
    }

    int sum = 0;
    for (int i = 0; i < len; i += 1) {
        sum += arr[i];
    }
    if ((sum % 3) != 0) {
        return false;
    }

    const int target = sum / 3;
    int cnt = 0;
    int curr_sum = 0;
    for (int i = 0; i < len; i += 1) {
        curr_sum += arr[i];
        if (curr_sum == target) {
            cnt += 1;
            if (cnt == 3) {
                return true;
            }
            curr_sum = 0;
        }
    }

    return false;
}
