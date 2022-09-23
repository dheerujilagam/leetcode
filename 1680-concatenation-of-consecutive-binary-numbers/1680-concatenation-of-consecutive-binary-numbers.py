class Solution:
    def concatenatedBinary(self, n: int) -> int:
        st=""
        for i  in range(1,n+1):
            st+=bin(i)[2:]
        return (int(st,2))%(1000000007)