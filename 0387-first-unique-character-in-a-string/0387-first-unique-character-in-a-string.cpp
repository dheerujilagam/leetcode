class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (auto it: s) mp[it]++;
        
        int sl = s.size();
        for (int i=0; i<sl; i++) {
            if (mp[s[i]]==1) {
                return i;
            } 
        }
        return -1;
    }
};