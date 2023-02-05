class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        if(n<m)
            return {};
        vector<int>res;
        vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<m;i++){
            v1[s[i]-'a']++;
            v2[p[i]-'a']++;
        }
        if(v1==v2)
            res.push_back(0);
        int j=0;
        for(int i=m;i<n;i++){
            v1[s[j]-'a']--;
            v1[s[i]-'a']++;
            j++;
            if(v1==v2)
                res.push_back(j);
        }
        return res;
    }
};