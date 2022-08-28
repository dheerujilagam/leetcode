class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int val=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            val=gcd(val,nums[i]);
        }
        if(val==1)
            return 1;
        else
            return 0;
    }
};