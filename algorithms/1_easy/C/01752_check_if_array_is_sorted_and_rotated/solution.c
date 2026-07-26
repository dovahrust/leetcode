bool check(const int* nums, const int len)
{
    assert(len >= 1 && nums != NULL);

    int hi = len - 1;
    while (hi > 0 && nums[hi - 1] <= nums[hi]) {
        hi -= 1;
    }

    if (hi == 0) {
        return true;
    }

    int lo = 0;
    while (lo + 1 < len && nums[lo] <= nums[lo + 1]) {
        lo += 1;
    }

    return lo +  1 == hi && nums[0] >= nums[len - 1];
}
