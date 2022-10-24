class Solution:
    def maxLength(self, arr: List[str]) -> int:
        dp = ['']
        ans = 0
        for i in arr:
            for s in dp:
                if len(i)+len(s)==len(set(i+s)):
                    dp.append(i+s)
                    ans = max(ans,len(i+s))
        return ans