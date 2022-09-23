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
        long long ans=0,mod=1000000007;
        for(int i=1;i<=n;i++){
            string s=DToB(i);
            ans=(((ans<<s.size())%mod)+i)%mod;
        }
        return ans;
    }
};