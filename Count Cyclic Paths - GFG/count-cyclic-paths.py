#User function Template for python3

class Solution:
    def countPaths (self, N):
        # code here 
        mod = 1000000007
        ans = 0 
        for i in range(2, N + 1):
            ans = (ans * 3) % mod
            if i & 1:
                ans = (ans - 3) % mod
            else:
                ans = (ans + 3) % mod
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        
        ob = Solution()
        print(ob.countPaths(N))

# } Driver Code Ends