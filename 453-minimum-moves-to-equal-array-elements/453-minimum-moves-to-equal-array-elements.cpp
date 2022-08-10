class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int sum=0;
        for(auto it:nums)
            sum+=it;
        return sum-mn*nums.size();
    }
};