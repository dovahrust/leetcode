class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        prev, prev_prev = (0, 0)

        for c in cost:
            curr = c + min(prev, prev_prev)
            prev_prev, prev = (prev, curr)

        return min(prev, prev_prev)
