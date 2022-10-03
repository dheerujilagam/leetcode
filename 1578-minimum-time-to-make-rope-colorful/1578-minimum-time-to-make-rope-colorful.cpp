class Solution {
public:
    int minCost(string c, vector<int>& nt) {
        int t=accumulate(nt.begin(),nt.end(),0);
        int mx=nt[0];
        for(int i=1;i<c.size();i++){
            if(c[i]==c[i-1])
                mx=max(mx,nt[i]);
            else{
                t-=mx;
                mx=nt[i];
            }
        }
        t-=mx;
        return t;
    }
};