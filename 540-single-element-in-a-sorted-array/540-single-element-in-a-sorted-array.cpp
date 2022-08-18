class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int val=0;
        for(auto i:nums)
            val=val^i;
        return val;
    }
};