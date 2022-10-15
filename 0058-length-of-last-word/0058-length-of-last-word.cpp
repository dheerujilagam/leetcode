class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<string>pq;
        string str="";
        for(auto c:s){
            if((c<='z' and c>='a') or (c<='Z' and c>='A')){
                str=c+str;
            }
            else{
                if(str!=""){
                    pq.push(str);
                    str="";
                }
            }
        }
        if(str!="")
        pq.push(str);
        return (pq.top()).size();
    }
};