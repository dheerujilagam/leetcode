class Solution {
public:
    string sortSentence(string s) {
        map<int,string>mp;
        int i=0;
        string str="";
        for(int j=0;j<s.size();j++){
            if(!isdigit(s[j]))
                str+=s[j];
            else{
                mp[s[j]-'0']=str;
                j++;
                str="";
            }
        }
        string ans="";
        for(auto it:mp)
            ans+=it.second+" ";
        return ans.substr(0,ans.size()-1);
    }
};