class Solution {
public:
    int numWaterBottles(int n, int k) {
        int ct=n;
        while(n>=k){
            ct+=(n/k);
            n=(n/k)+(n%k);
        }
        return ct;
    }
};