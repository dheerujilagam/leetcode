class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mp;
        for(int i=0;i<words2.size();i++){
            unordered_map<char,int>temp;
            for(int j=0;j<words2[i].size();j++){
                temp[words2[i][j]]++;
                mp[words2[i][j]] = max(mp[words2[i][j]],temp[words2[i][j]]);
            }
        }
        vector<string>ans;
        for(int i=0;i<words1.size();i++){
            unordered_map<char,int>ump;
            bool flag = true;
            for(int j=0;j<words1[i].size();j++)
                ump[words1[i][j]]++;
            for(auto& it:mp){
                if(it.second > ump[it.first])
                    flag = false;
            }
            if(flag)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};