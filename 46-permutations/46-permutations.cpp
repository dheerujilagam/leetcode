class Solution {
public:
    vector<vector<int>>ans;
    void per(vector<int>&nums, int id, int n){
        if(id==n)
            ans.push_back(nums);
        else{
            for(int i=id;i<=n;i++){
                swap(nums[id],nums[i]);
                per(nums,id+1,n);
                swap(nums[id],nums[i]);
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums,0,nums.size()-1);
        return ans;
    }
};