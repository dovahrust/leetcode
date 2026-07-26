static int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int maximumProduct(const int* nums, const int len)
{
    assert(len >= 3 && nums != NULL);
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < len; i += 1) {
        const int num = nums[i];
        if (num < min1) {
            min2 = min1;
            min1  = num;
        } else if (num < min2) {
            min2 = num;
        }

        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }
    }

    return max_int(min1 * min2 * max1, max3 * max2 * max1);
}
