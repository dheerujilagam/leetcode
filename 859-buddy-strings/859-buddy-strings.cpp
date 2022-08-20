class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        vector<char>m1,m2;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                m1.push_back(s[i]);
                m2.push_back(goal[i]);
            }
        }
        reverse(m2.begin(),m2.end());
        if(m1.size()==2 and m1==m2) return true;
        set<char>st(s.begin(),s.end());
        if(m1.size()==0){
            if(s.size()>st.size()) return true;
        }
        return false;
    }
};