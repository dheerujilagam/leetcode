class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j= nums.size()-1;
        vector<int> arr;
        while (i<j) {
            if (abs(nums[i]) <= abs(nums[j])) {
                arr.push_back (nums[j]*nums[j]);
                j--;
            }
            else {
                arr.push_back (nums[i]*nums[i]);
                i++;
            }
        }
        arr.push_back (pow(nums[j],2));
        reverse(arr.begin(), arr.end());
        return arr;
    }
};