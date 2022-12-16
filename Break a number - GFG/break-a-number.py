#User function Template for python3


class Solution:
    def waysToBreakNumber(self, n):
        #code here
        mod = 1000000007
        n += 1
        return (n*(n+1)//2)%mod


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        ob = Solution()
        print(ob.waysToBreakNumber(n))
        
# } Driver Code Ends