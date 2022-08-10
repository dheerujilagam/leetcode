class Solution {
public:
    bool static comp(string &s1,string &s2){
        if(s1.length()==s2.length()){
            for(int i=0;i<s1.length();i++){
                if(s1[i]==s2[i]) continue;
                else return s1[i]>s2[i];
            }
        }
        return s1.length()>s2.length();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        return nums[k-1];
    }
};