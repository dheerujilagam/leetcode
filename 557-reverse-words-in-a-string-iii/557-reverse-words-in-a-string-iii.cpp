class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string str="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=32){
                st.push(s[i]);
            }
            else if(s[i]==32){
                while(!st.empty()){
                    char c;
                    c = st.top();
                    st.pop();
                    str+=c;
                }
                str+=" ";
            }
        }
        str.erase(str.size()-1);
        return str;
    }
};