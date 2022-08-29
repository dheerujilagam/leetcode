class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n1=len(nums)
        n2=len(set(nums))
        if n1!=n2:
            return True
        else:
            return False