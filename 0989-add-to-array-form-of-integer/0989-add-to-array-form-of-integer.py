class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        s=""
        for i in num:
            s+=str(i)
        ans=int(s)+k
        ans=list(str(ans))
        return ans;