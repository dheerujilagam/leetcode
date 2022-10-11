class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return false;
        int l=INT_MAX,r=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=l)
                l=nums[i];
            else if(nums[i]<=r)
                r=nums[i];
            else
                return true;
        }
        return false;
    }
};