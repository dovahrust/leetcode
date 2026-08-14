class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        n = len(s)
        freqs = [0] * 256
        lo = 0
        res = 0

        for hi in range(n):
            freqs[ord(s[hi])] += 1

            while freqs[ord(s[hi])] > 2:
                freqs[ord(s[lo])] -= 1
                lo += 1

            res = max(res, hi + 1 - lo)

        return res
