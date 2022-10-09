class Solution {
    public int maxSubArray(int[] nums) {
        int mx=Integer.MIN_VALUE,cur=0;
        for(int i=0;i<nums.length;i++){
            cur+=nums[i];
            if(cur>mx)
                mx=cur;
            if(cur<0)
                cur=0;
        }
        return mx;
    }
}