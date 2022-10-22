class Solution {
public:
    bool check(unordered_map<char,int>& m1, unordered_map<char,int>& m2){
        if(m2.size() < m1.size())
            return false;
        for(auto it:m1){
            if(it.second > m2[it.first])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>m1,m2;
        for(auto c:t)
            m1[c]++;
        int n=s.size(),st=0,ans=INT_MAX;
        string str;
        for(int i=0;i<n;i++){
            if(m1.find(s[i])!=m1.end())
                m2[s[i]]++;
            while(check(m1,m2)){
                if(ans>(i-st+1)){
                    ans=(i-st+1);
                    str=s.substr(st,i-st+1);
                }
                if(m2.find(s[st])!=m2.end())
                    m2[s[st]]--;
                st++;
            }
        }
        return str;
    }
};