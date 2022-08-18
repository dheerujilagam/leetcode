class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        for(auto i:arr)
            mp[i]++;
        priority_queue<int>pq;
        for(auto it:mp)
            pq.push(it.second);
        int c=0,sum=0,n=arr.size();
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
            c++;
            if(sum>=n/2)
                break;
        }
        return c;
    }
};