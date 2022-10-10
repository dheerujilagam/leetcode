class Solution {
public:
    string breakPalindrome(string p) {
        int n=p.size();
        if(n==1){
            return "";
        }
        for(int i=0;i<n/2;i++){
            if(p[i]!=97){
                p[i]=97;
                return p;
            }
        }
        p[n-1]=98;
        return p;
    }
};