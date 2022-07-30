class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int siso[127]={0},tiso[127]={0};
        int n=s.size(),i;
        for(i=0;i<n;i++){
            if(siso[s[i]]!=tiso[t[i]])
                return false;
            siso[s[i]] = tiso[t[i]] = i+1; 
        }
        return true;
    }
};