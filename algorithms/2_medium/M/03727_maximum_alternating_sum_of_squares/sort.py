class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        num_len = len(nums)
        nums.sort(key = lambda x: abs(x))
        plus_index = num_len//2;
        t_sum = 0

        for i in range(plus_index):
            t_sum -= nums[i] ** 2

        for i in range(plus_index, num_len):
            t_sum += nums[i] ** 2

        return t_sum
