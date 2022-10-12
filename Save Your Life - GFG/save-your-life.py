#User function Template for python3


class Solution:
    def maxSum (self, w, x, b, n):
        #code here
        if len(w)==1:
            return w
        mx=0
        ans=""
        tem=""
        cur=0
        for i in range(0,len(w)):
            if w[i] in x:
                cur+=b[x.index(w[i])]
            else:
                cur+=ord(w[i])
            tem+=w[i]
            if mx<cur:
                ans=tem
                #print(ans)
                mx=cur
            if cur<0:
                cur=0
                tem=""
        if(cur>mx):
            ans=tem
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        w = input()
        n = int(input())
        x = input().split(' ')
        b = input().split(' ')
        for itr in range(n):
            b[itr] = int(b[itr])
       

        ob = Solution()
        print(ob.maxSum(w,x,b,n))
# } Driver Code Ends