class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int val=0;
        for(int i=0;i<nums.size();i++){
            val=gcd(val,nums[i]);
            if(val==1)
                return 1;
        }
        return 0;
    }
};