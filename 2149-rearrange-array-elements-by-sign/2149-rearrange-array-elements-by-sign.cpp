class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int>q1,q2;
        for(auto i:nums){
            if(i>0)
                q1.push(i);
            else
                q2.push(i);
        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=q1.front();
                q1.pop();
            }
            else{
                nums[i]=q2.front();
                q2.pop();
            }
        }
        return nums;
    }
};