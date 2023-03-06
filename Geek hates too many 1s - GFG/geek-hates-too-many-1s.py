class Solution:
    def noConseBits(self, n : int) -> int:
        # code here
        s = list(bin(n)[2:])
        cnt = 0
        for i in range(len(s)):
            if s[i] == "1":
                if cnt == 2:
                    s[i] = "0"
                    cnt = 0
                else:
                    cnt += 1
            else:
                cnt = 0
        return int("".join(s),2)
            
            



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.noConseBits(n)
        
        print(res)
        

# } Driver Code Ends