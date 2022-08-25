class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            int i=0;
            string t=s;
            for(int i=0;i<s.size();i++){
                s=s.substr(1)+s.substr(0,1);
                if(t.compare(s)>0)
                    t=s;
            }
            return t;
        }
        sort(s.begin(),s.end());
        return s;
    }
};