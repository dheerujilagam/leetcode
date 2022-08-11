class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;
        int power = 5;
        for (int i = 1;; i++) {
            zeroes += (n / power);
            if (n / power == 0) {
                break;
            }
            power *= 5;
        }
    return zeroes;
    }
};