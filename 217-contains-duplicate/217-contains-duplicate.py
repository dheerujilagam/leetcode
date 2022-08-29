class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        d={}
        for i in nums:
            if i not in d:
                d[i]=1;
            else:
                d[i]+=1
        for v in d.values():
            if v>=2:
                return True
        return False