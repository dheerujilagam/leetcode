class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int dif=0;
        for(int i=0;i<nums.size()-1;i++){
            dif=max(dif,nums[i+1]-nums[i]);
        }
        return dif;
    }
};