class Solution {
public:
    int pos(int val){
        int ind=0;
        while(val){
            if(val&1)
                return ind;
            val=val>>1;
            ind++;
        }
        return ind;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int val=0;
        for(auto i:nums)
            val=val^i;
        int t=val;
        int index=pos(t);
        for(int i=0;i<nums.size();i++){
            int temp=1<<index;
            if(nums[i]&temp)
                t^=nums[i];
        }
        return {t,t^val};
    }
};