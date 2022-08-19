class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)
            mp[i]++;
        int val=nums.size()/3;
        vector<int>ans;
        for(auto it:mp){
            if(it.second>val)
                ans.push_back(it.first);
        }
        return ans;
    }
};