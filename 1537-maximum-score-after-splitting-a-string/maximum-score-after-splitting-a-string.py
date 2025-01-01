class Solution:
    def maxScore(self, s: str) -> int:
        a = [0] * len(s)
        b = [0] * (len(s) + 1)
        a[0] = (1 if s[0] == '0' else 0)
        for _ in range(1, len(s)):
            a[_] = a[_ - 1] + (1 if s[_] == '0' else 0)

        b[-1] = 0
        b[len(s) - 1] = (1 if s[-1] == '1' else 0)
        for _ in range(len(s) - 2, -1, -1):
            b[_] = b[_ + 1] + (1 if s[_] == '1' else 0)
        
        max_score = 0
        for r in range(len(s) - 1):
            max_score = max(max_score, a[r] + b[r + 1])

        return max_score
