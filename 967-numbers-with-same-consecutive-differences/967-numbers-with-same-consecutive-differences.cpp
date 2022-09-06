class Solution {
public:
    vector<int>ans;
    void fun(int n, int k, int val, int sum){
        if(val<0 or val>9) return ;
        if(n==0){
            auto it=find(ans.begin(),ans.end(),(sum*10)+val);
            if(it==ans.end()) ans.push_back((sum*10)+val);
        }
        else{
            sum=(sum*10)+val;
            fun(n-1,k,val-k,sum);
            fun(n-1,k,val+k,sum);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            fun(n-1,k,i,0);
        }
        return ans;
    }
};