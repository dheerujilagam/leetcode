class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int z=0,o=0;
        while(n){
            if(n&1) o++;
            else z++;
            n=n>>1;
        }
        return (z%2==0)and(o==1);
    }
};