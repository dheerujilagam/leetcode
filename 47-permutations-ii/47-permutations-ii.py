class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        per = permutations(nums)
        per = set(per)
        return per