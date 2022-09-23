class Solution {
public:
    string DToB(int num){
        string str;
        while(num){
            if(num & 1)
                str+='1';
            else
                str+='0';
            num>>=1; 
        }   
        return str;
    }
    int concatenatedBinary(int n) {
        long mod=1000000007,l=0,ans=0;
        for(int i=1;i<=n;i++){
            l=log2(i)+1;
            ans=((ans<<l)+i)%mod;
        }
        return ans;
    }
};