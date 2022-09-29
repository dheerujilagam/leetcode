class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push_back({abs(x-arr[i]),i});
        }
        sort(pq.begin(),pq.end());
        vector<int>v;
        for(int i=0;i<k;i++)
            v.push_back(arr[pq[i].second]);
        sort(v.begin(),v.end());
        return v;
    }
};