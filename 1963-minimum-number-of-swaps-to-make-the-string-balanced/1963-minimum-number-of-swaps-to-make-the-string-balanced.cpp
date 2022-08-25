class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                if(!st.empty()){
                    if(st.top()=='[')
                        st.pop();
                }
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        if(st.size()==2) return 1;
        else{
            return st.size()/2;
        }
    }
};