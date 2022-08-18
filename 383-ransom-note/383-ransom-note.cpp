class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<int,int>m1,m2;
        for(auto c:r)
            m1[c]++;
        for(auto c:m)
            m2[c]++;
        bool flag=true;
        for(auto it:m1){
            if(it.second>m2[it.first]){
                flag=false;
                break;
            }
        }
        return flag;
    }
};