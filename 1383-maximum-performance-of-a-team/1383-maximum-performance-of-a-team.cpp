class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        long long mod=1e9+7;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
            vp.push_back({e[i],s[i]});
        sort(vp.begin(),vp.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long t=0,mx=0;
        for(int i=n-1;i>=0;i--){
            t+=vp[i].second;
            pq.push(vp[i].second);
            if(pq.size()>k){
                t-=pq.top();
                pq.pop();
            }
            mx=max(mx,(t*vp[i].first));
        }
        return mx%mod;
    }
};