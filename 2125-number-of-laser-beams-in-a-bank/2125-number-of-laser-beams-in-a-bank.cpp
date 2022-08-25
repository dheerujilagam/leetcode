class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size()==1) return 0;
        vector<int>ans;
        for(auto str:bank){
            int ct=0;
            for(auto c:str){
                if(c=='1')
                    ++ct;
            }
            if(ct!=0)
                ans.push_back(ct);
        }
        if(ans.size()==1) return 0;
        int sum=0;
        for(int i=1;i<ans.size();i++)
            sum+=ans[i]*ans[i-1];
        return sum;
    }
};