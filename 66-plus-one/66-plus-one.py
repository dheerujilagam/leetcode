class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        l=map(str,digits)
        num = int(''.join(l))+1
        num = str(num)
        return list(map(int,list(num)))