class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1])
                c++;
        }
        if(c==nums.size()-1)
            return true;
        c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1])
                c++;
        }
        if(c==nums.size()-1)
            return true;
        return false;
    }
};