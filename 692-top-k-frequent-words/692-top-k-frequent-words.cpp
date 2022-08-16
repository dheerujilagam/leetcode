class Solution {
public:
    bool static helper(pair<string, int> &p1, pair<string, int> &p2){
        if(p1.second == p2.second)
            return p1.first<p2.first;
        return p1.second>p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(const string& i:words)
            mp[i]++;
        vector<pair<string, int>> v;
        for(auto &i : mp)
            v.push_back(i);
        sort(v.begin(), v.end(), helper);
        vector<string> ans;
        for(auto &i : v){
            if(k){
                ans.push_back(i.first), 
                k--;
            }
            else break;
        }
        return ans;
    }
};