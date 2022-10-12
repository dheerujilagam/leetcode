class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int p=INT_MAX;
        int m=0;
        for(int i=0;i<pr.size();i++){
                p=min(p,pr[i]);
                m=max(m,pr[i]-p);  
        }
        return m;
    }
};