class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size() && i<k+1;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
                return 1;
        }
        for(int i=k+1;i<nums.size();i++){
            mp[nums[i-k-1]]--;
            mp[nums[i]]++;
            if(mp[nums[i]]>>1)
                return true;
        }
        return false;
    }
};