class Solution {
public:
    unsigned long int catalan(int n){
        unsigned long int ctln[n+1];
        ctln[0]=ctln[1]=1;
        for (int i=2;i<=n;i++) {
            ctln[i]=0;
            for (int j=0;j<i;j++)
                ctln[i]+= ctln[j]*ctln[i-j-1];
        }
        return ctln[n];
    }
    int numTrees(int n) {
        if(n==1)
            return 1;
        return catalan(n);
    }
};