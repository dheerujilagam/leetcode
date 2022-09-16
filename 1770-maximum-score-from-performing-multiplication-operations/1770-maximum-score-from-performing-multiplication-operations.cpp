class Solution {
public:
    vector<vector<int>>dp;
    int mul(vector<int>& nums, vector<int>& multipliers, int l, int r, int index){
        int n=nums.size(),m=multipliers.size();
        if(index>=m)
            return 0;
        if(dp[index][l]!=INT_MIN)
            return dp[index][l];
        int val=multipliers[index];
        return dp[index][l]=max(nums[l]*val+mul(nums,multipliers,l+1,r,index+1),nums[r]*val+mul(nums,multipliers,l,r-1,index+1));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(),m=multipliers.size();
        int l=0,r=n-1,index=0;
        dp.assign(m+1,vector<int>(m+1,INT_MIN));
        return mul(nums,multipliers,l,r,index);
    }
};