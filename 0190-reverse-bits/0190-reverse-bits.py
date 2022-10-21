class Solution:
    def reverseBits(self, n: int) -> int:
        num =str(n)
        num=bin(int(num))[2:]
        num='0'*(32-len(num))+num
        return int(num[::-1],2)