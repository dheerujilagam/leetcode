class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum=0;
        for(auto i:nums){
            pq.push(i);
            sum+=i;
        }
        int c=0;
        double temp=0;
        while(temp<sum/2){
            double val = pq.top();
            pq.pop();
            temp+=val/2;
            pq.push(val/2);
            c++;
        }
        return c;
    }
};