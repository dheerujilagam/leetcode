class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int>q1,q2;
        int c=0;
        for(auto i:nums){
            if(i<pivot)
                q1.push(i);
            if(i>pivot)
                q2.push(i);
            if(i==pivot)
                c++;
        }
        vector<int>v;
        while(!q1.empty()){
            v.push_back(q1.front());
            q1.pop();
        }
        while(c--)
            v.push_back(pivot);
        while(!q2.empty()){
            v.push_back(q2.front());
            q2.pop();
        }
        return v;
    }
};