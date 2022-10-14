class Solution:
    def addBinary(self, a: str, b: str) -> str:
        self.a=a
        self.b=b
        return((bin(int(a,2)+int(b,2))).replace("0b",""))