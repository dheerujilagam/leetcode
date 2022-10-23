class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0,n=nums.size(),p=0,pro=1;
        for(int i=0;i<n;i++){
            pro*=nums[i];
            while(pro>=k and p<=i){
                pro/=nums[p];
                p++;
            }
            cnt+=(i-p+1);
        }
        return cnt;
    }
};