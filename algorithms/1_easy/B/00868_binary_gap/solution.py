class Solution:
    def binaryGap(self, n: int) -> int:
        while n > 0 and (n & 1) != 1:
            n >>= 1

        cnt = 0
        res = 0

        while n > 1:
            if (n & 1) == 1:
                cnt = 1
            else:
                cnt += 1

            res = max(res, cnt)
            n >>= 1

        return res
