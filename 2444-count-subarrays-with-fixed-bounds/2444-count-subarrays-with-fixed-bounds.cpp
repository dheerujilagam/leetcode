class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minp = -1, maxp = -1, p = -1, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == minK) minp = i;
            if(nums[i] == maxK) maxp = i;
            if(nums[i] < minK || nums[i] > maxK) p = i;
            ans += max(0, min(minp, maxp) - p);
        }
        return ans;
    }
};