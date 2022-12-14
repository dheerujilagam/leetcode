class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums)
            mp[i]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
            pq.push(make_pair(it.second,it.first));
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};