class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                st.push({s[i],i});
                if(st.top().first==')' and st.size()==1){
                    s.erase(i,1);
                    i--;
                    st.pop();
                }
                else if(st.size()!=1){
                    if(st.top().first==')'){
                        st.pop();
                        st.pop();
                    }
                }
            }
        }
        while(st.empty()==false){
            s.erase(st.top().second,1);
            st.pop();
        }
        return s;
    }
};