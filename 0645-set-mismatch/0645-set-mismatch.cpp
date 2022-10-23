class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)
            mp[i]++;
        int f,s;
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)==mp.end())
                s=i;
            if(mp[i]>1)
                f=i;
        }
        return {f,s};
    }
};