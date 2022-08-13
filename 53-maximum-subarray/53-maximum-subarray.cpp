class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN;
        int t=0;
        for(auto i:nums){
            t+=i;
            mx=max(mx,t);
            if(t<0)
                t=0;
        }
        return mx;
    }
};