int maxProduct(const int* nums, int len)
{
    assert(len >= 2 && nums != NULL);
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for(int i = 0; i < len; i += 1) {
        if (nums[i] >= max1) {
            max2 = max1;
            max1 = nums[i];
        } else if(nums[i] >= max2) {
            max2 = nums[i];
        }
    }

    return (max1 - 1) * (max2 - 1);
}
