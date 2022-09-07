class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<long long,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        for(auto it:mp){
            if(it.second.size()>=2){
                for(long long i=0;i<it.second.size()-1;i++){
                    for(long long j=i+1;j<it.second.size();j++){
                        if(abs(it.second[j]-it.second[i])<=k)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};