class Solution:
    def minimumPushes(self, word: str) -> int:
        assert(len(word) <= 26)
        n = len(word)

        return n + (n - min(n, 8)) + (n - min(n, 16)) +  (n - min(n, 24))
