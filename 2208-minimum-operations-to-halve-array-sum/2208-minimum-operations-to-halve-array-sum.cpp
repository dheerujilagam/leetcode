class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        priority_queue<double> pq;
        for(auto num:nums) {
            sum+=num;
            pq.push(num);
        }
        
        int c=0;
        double temp=0;
        while(temp<sum/2) {
            double curNum=pq.top();
            double newNum=curNum/2;
            temp+=newNum;
            pq.pop();
            pq.push(newNum);
            c++;
        }
        
        return c;
    }
};