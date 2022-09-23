class Solution {
public:
    int DToB(int num){
        int str=0;
        while(num){
            str++;
            num>>=1; 
        }   
        return str;
    }
    int concatenatedBinary(int n) {
        long long ans=0,mod=1000000007;
        for(int i=1;i<=n;i++){
            int l=DToB(i);
            ans=((ans<<l%mod)+i)%mod;
        }
        return ans;
    }
};