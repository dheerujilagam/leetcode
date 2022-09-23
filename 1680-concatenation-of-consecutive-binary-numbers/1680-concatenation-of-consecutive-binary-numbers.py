class Solution:
    def concatenatedBinary(self, n: int) -> int:
        st=""
        for i  in range(1,n+1):
            s=str(bin(i))[2:]
            st+=s
        val=int(st,2)
        mod=(10**9)+7
        return val%mod