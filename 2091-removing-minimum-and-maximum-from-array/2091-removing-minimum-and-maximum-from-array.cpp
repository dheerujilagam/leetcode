class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int mn=0,mx=0;
        for(int i=1;i<n;i++){
            if(nums[mn]>nums[i]){
                mn=i;
            }
            if(nums[mx]<nums[i]){
                mx=i;
            }
        }
        int mx_i=max(mx,mn);
        int mn_i=min(mx,mn);
        int left=mx_i+1;
        int right=n-mn_i;
        int lr=mn_i+1+n-mx_i;
        return min({left,right,lr});
    }
};