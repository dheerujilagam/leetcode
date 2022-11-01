class Solution {
public:
    unordered_map<int,string>mp{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void solve(int id, int n, vector<int>a, vector<string>&res, string cur){
        if(id==n){
            res.push_back(cur);
            return ;
        }
        string t=mp[a[id]];
        for(auto c:t){
            cur.push_back(c);
            solve(id+1,n,a,res,cur);
            cur.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        vector<int>a;
        for(auto c:digits)
            a.push_back(c-'0');
        int n=a.size();
        vector<string>res;
        string cur;
        solve(0,n,a,res,cur);
        return res;
    }
};