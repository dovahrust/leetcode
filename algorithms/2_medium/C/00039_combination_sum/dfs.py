class Solution:
    def dfs(self, candidates, idx, target, res, tmp):
        if target == 0:
            res.append(tmp[:])
            return

        if target < 0 or idx >= len(candidates):
            return

        tmp.append(candidates[idx])
        self.dfs(candidates, idx, target - candidates[idx], res, tmp)
        tmp.pop()

        self.dfs(candidates, idx + 1, target, res, tmp)

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        tmp = []

        self.dfs(candidates, 0, target, res, tmp)

        return res
