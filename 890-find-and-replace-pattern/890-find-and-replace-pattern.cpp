class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto i:words){
                int c=0;
                bool flag = true;
                unordered_map<char, char> mp, m;
                for(auto j:i){
                    if(mp.find(pattern[c])==mp.end() && m.find(j)==m.end()){
                        mp[pattern[c]] = j;
                        m[j] = pattern[c];
                    }
                    else{
                        if(mp[pattern[c]] != j || m[j]!=pattern[c]){
                            flag=false;
                        }
                    }
                    c++;
                }
                
                if(flag) ans.push_back(i);
        }
        return ans;
    }
};