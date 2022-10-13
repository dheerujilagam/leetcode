class Solution:
    def evalRPN(self, t: List[str]) -> int:
        st=[]
        for i in range(0,len(t)):
            try:
                c=int(t[i])
                st.append(c)
            except:
                a=st[-1]
                st.pop()
                b=st[-1]
                st.pop()
                if t[i]=="+":
                    st.append(a+b)
                if t[i]=="-":
                    st.append(b-a)
                if t[i]=="*":
                    st.append(b*a)
                if t[i]=="/":
                    st.append(int(b/a))
                #print(st[-1])
        return st[0]