class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        int mp1[26];
        int mp2[26];
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        for(int i=0;i<s1.size();i++){
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
        }
        int start=0,end=s1.size();
        while(end<s2.size()){
            if(matches(mp1,mp2))
                return true;
            mp2[s2[end]-'a']++;
            mp2[s2[start]-'a']--;
            start++;
            end++;
        }
        if(matches(mp1,mp2))
            return true;
        return false;
    }
    bool matches(int mp1[],int mp2[]){
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i])
                return false;
        }
        return true;
    }
};