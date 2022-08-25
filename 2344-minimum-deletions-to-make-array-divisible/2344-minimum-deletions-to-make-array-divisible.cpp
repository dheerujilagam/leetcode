class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int val=0;
        for(int i=0;i<numsDivide.size();i++)
            val=gcd(val,numsDivide[i]);
        int c=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(val%nums[i]==0)
                return i;
        }
        return -1;
    }
};