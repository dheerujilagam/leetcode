class Solution {
public:
    string decodeString(string s) {
        stack<string>s1;
        stack<int>s2;
        string cur="";
        int n=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))
                n=(n*10)+s[i]-'0';
            else if(s[i]>='a' and s[i]<='z')
                cur+=s[i];
            else if(s[i]=='['){
                s1.push(cur);
                s2.push(n);
                cur="";
                n=0;
            }
            else if(s[i]==']'){
                string t="";
                int no=s2.top();
                for(int i=0;i<no;i++){
                    t+=cur;
                }
                cur=s1.top()+t;
                s1.pop();
                s2.pop();
            }
        }
        return cur;
    }
};