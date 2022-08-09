class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        for(int i=2;i*i<=n;i++){
            if(prime[i]==true){
                for(int j=i*i;j<=n;j+=i)
                    prime[j]=false;
            }
        }
        int c=0;
        for(int i=2;i<n;i++){
            if(prime[i])
                c++;
        }
        return c;
    }
};