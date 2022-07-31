class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n=numbers.size(),i=0;
        while(i<n){
            int start=i,end=n-1;
            if(numbers[start]+numbers[end]==target){
                ans.push_back(start+1);ans.push_back(end+1);
                break;
            }
            else if(numbers[start]+numbers[end]>target){n--;}
            else {i++;}
        }
        return ans;
    }
};