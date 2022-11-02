class Solution {
public:
    void solve(int id, vector<int>&dig, vector<vector<int>>&res, vector<int>t, int sum, int target){
        if(sum>target)
            return ;
        if(sum==target){
            res.push_back(t);
            return ;
        }
        for(int i=id;i<dig.size();i++){
            t.push_back(dig[i]);
            sum+=dig[i];
            solve(i,dig,res,t,sum,target);
            sum-=dig[i];
            t.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>&dig, int target) {
        vector<vector<int>>res;
        vector<int>t;
        int sum=0;
        solve(0,dig,res,t,sum,target);
        return res;
    }
};