class Solution {
public:
    int strStr(string haystack, string needle) {
        map<string,int>mp;
        int m=haystack.size(),n=needle.size();
        for(int i=0;i<=m-n;i++){
            string t="";
            int j=i;
            while(t.size()<n){
                t+=haystack[j];
                j++;
            }
            if(needle==t)
                return i;
        }
        return -1;
    }
};