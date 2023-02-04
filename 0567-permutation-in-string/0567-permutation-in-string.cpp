class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>dp(26,0);
        int n=s1.size(),m=s2.size();
        if(m<n)
            return false;
        for(int i=0;i<n;i++){
            dp[s1[i]-'a']++;
            dp[s2[i]-'a']--;
        }
        int k=0;
        for(int i=n;i<m;i++){
            int c=0;
            for(int i=0;i<26;i++){
                if(dp[i]!=0)
                    break;
                c++;
            }
            if(c==26)
                return true;
            dp[s2[k++]-'a']++;
            dp[s2[i]-'a']--;
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(dp[i]!=0)
                break;
            c++;
        }
        if(c==26)
            return true;
        return false;
    }
};