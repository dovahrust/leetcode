class Solution:
    def rob(self, nums: List[int]) -> int:
        prev, prev_prev = (0, 0)

        for num in nums:
            curr = num + prev_prev
            prev_prev = max(prev_prev, prev)
            prev = curr

        return max(prev, prev_prev)
