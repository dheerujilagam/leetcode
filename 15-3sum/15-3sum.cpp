class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            vector<int>temp;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    // auto it = find(ans.begin(),ans.end(),temp);
                    // if(temp.size()!=0 && it==ans.end()){
                    //     ans.push_back(temp);
                    //     temp.clear();
                    //     break;
                    // 
                    ans.insert(temp);
                    temp.clear();
                }
                if(sum<0)
                    ++j;
                else
                    --k;
            }
        }
        //return ans;
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};