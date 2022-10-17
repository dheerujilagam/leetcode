class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<vector<int>>pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            pq.push({x*x+y*y,x,y});
        }
        while(pq.size()>k){
            pq.pop();
        }
        while(!pq.empty()){
            vector<int>t=pq.top();
            pq.pop();
            ans.push_back({t[1],t[2]});
        }
        return ans;
    }
};