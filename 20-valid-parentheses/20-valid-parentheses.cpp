class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                st.push(s[i]);
            }
            else{
                if(s[i] == ')'){
                    if(st.size() == 0) return false;
                    else{
                    if(st.top() != '(') return false;
                    else st.pop();
                }
            }
            else if(s[i] == ']'){
                if(st.size() == 0) return false;
                else{
                    if(st.top() != '[') return false;
                    else st.pop();
                }
            }
            else if(s[i] == '}' ){
                if(st.size() == 0) return false;
                else{
                    if(st.top() != '{') return false;
                    else st.pop();
                }
            }
            }
        }
        return st.size() == 0;
    }
};