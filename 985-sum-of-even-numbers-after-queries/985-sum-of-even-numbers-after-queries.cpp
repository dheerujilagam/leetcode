class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int sum=0;
        for(auto i:nums){
            if(i%2==0)
                sum+=i;
        }
        for(int i=0;i<queries.size();i++){
            if(nums[queries[i][1]]&1){
                nums[queries[i][1]]+=queries[i][0];
                if(nums[queries[i][1]]%2==0)
                    sum+=nums[queries[i][1]];
            }
            else{
                sum-=nums[queries[i][1]];
                nums[queries[i][1]]+=queries[i][0];
                if(nums[queries[i][1]]%2==0)
                    sum+=nums[queries[i][1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};