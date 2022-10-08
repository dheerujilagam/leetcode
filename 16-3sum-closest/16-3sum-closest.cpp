class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1e5;
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int val=nums[i]+nums[l]+nums[r];
                if(abs(ans-target)>abs(target-val))
                    ans=val;
                if(val<target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};