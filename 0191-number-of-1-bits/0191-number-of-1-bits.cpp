class Solution {
public:
    int hammingWeight(uint32_t n) {
       int count=0;
        while(n)
        {
            int temp=n%2;
            if(temp==1)
            {
                count++;
            }
            n/=2;
        }
        return count;
    }
};