class Solution {
    public void solve(String cur, int op, int cl, int n, List<String>res){
        if(op>n || cl>n || cl>op)
            return ;
        if(op==n && cl==n){
            res.add(cur);
            return ;
        }
        solve(cur+'(',op+1,cl,n,res);
        solve(cur+')',op,cl+1,n,res);
        return ;
    }
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        solve("",0,0,n,res);
        return res;
    }
}