class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>>cnt(26,vector<int>(26,0));
        int ans=0;
        for(auto it:words){
            int x=it[0]-'a',y=it[1]-'a';
            if(cnt[y][x]){
                ans+=4;
                cnt[y][x]--;
            }
            else
                cnt[x][y]++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i][i]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};