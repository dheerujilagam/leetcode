class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        per = permutations(nums)
        return per