class Solution {
public:
    void solve(string cur, int open, int close, int n, vector<string>&res){
        if(open>n || close>n || close>open)
            return ;
        if(open==n && close==n){
            res.push_back(cur);
            return ;
        }
        solve(cur+'(',open+1,close,n,res);
        solve(cur+')',open,close+1,n,res);
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve("",0,0,n,res);
        return res;
    }
};