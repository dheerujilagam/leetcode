class Solution {
public:
    vector<int>v;
    int cnt(int i, string s, vector<int>&v){
        if(i>=s.size())
            return 1;
        else if(s[i]=='0')
            return 0;
        else if(v[i]!=-1)
            return v[i];
        else if(i==s.size()-1)
            return 1;
        else if(s[i]=='1' or (s[i]=='2' and s[i+1]-'0'>=0 and s[i+1]-'0'<=6))
            return v[i]=cnt(i+1,s,v)+cnt(i+2,s,v);
        else
            return v[i]=cnt(i+1,s,v);
    }
    int numDecodings(string s) {
        vector<int>v(s.size(),-1);
        return cnt(0,s,v);
    }
};