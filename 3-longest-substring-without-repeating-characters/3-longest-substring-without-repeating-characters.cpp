class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mp;
            string str=s.substr(i,s.size()-i);
            //cout<<str<<" ";
            for(int j=0;j<str.size();j++){
                if(mp[str[j]]==0)
                    mp[str[j]]++;
                else
                    break;
            }
            if(mx<mp.size())
                mx=mp.size();
        }
        return mx;
    }
};