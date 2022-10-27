class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(auto i : s)
            ++freq[i];
        int ans=0;
        bool odd = false;
        for(auto i:freq){
            ans+=i.second;
            if(i.second%2!=0){
                --ans; 
                odd=true;
            }
        }
        if(odd) ++ans;
        return ans;
    }
};