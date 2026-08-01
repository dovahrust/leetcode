def dfs(nums, lo, hi, p1_turn, balance):
    if lo > hi:
        return balance >= 0

    if p1_turn:
        return dfs(nums, lo + 1, hi, not p1_turn, balance + nums[lo]) or \
               dfs(nums, lo, hi - 1, not p1_turn, balance + nums[hi])
    else:
        return dfs(nums, lo + 1, hi, not p1_turn, balance - nums[lo]) and \
               dfs(nums, lo, hi - 1, not p1_turn, balance - nums[hi])

class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        return dfs(nums, 0, len(nums) - 1, True, 0)
