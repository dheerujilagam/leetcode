class Solution {
public:
    vector<string>ans;
    void fun(string cur, string s, int i){
        if(i==s.size()){
            ans.push_back(cur);
            return ;
        }
        if(isdigit(s[i])){
            cur+=s[i];
            fun(cur,s,i+1);
        }
        else{
            string s1=cur;
            s1+=tolower(s[i]);
            fun(s1,s,i+1);
            string s2=cur;
            s2+=toupper(s[i]);
            fun(s2,s,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        fun("",s,0);
        return ans;
    }
};