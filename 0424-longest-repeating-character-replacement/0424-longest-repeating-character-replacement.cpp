class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0,res=0,mx=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            for(auto it:mp){
                if(mx<it.second)
                    mx=it.second;
            }
            if((i-l+1)-mx>k){
                mp[s[l]]--;
                l++;
                for(auto it:mp){
                    if(mx<it.second)
                        mx=it.second;
                }
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};