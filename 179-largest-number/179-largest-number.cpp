class Solution {
public:
    static bool check(int &a, int &b){
        string s1 = to_string(a)+to_string(b);
        string s2 = to_string(b)+to_string(a);
        if(s1>s2) return true;
        else return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),check);
        string s = "";
        for(auto it:nums)
            s+=to_string(it);
        int c=0;
        for(auto it:s){
            if(it-'0'==0)
                c++;
        }
        if(c==s.size()) return "0";
        return s;
    }
};