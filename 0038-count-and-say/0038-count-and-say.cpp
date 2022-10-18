class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s="1";
        for(int i=1;i<n;i++){
            s = say(s);
        }
        return s;
    }
    string say(string s){
        string temp = "";
        int c=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])
                c++;
            else{
                temp+=to_string(c)+s[i];
                c=1;
            }
        }
        temp+=to_string(c)+s[s.size()-1];
        return temp;
    }
};