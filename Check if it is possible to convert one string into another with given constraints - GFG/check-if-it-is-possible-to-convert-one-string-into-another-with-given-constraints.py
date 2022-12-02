#User function Template for python3

class Solution:
    def isItPossible(sef, S, T, M, N):
        #code here
        S=S.replace('#','')
        T=T.replace('#','')
        if S==T:
            return 1
        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        S,T=input().split()
        ob=Solution()
        print(ob.isItPossible(S,T,len(S),len(T)))
# } Driver Code Ends