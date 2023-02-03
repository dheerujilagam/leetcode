class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>res(numRows);
        int i=0,n=s.size();
        while(i<n){
            for(int j=0;j<numRows && i<n;j++)
                res[j].push_back(s[i++]);
            
            for(int j=numRows-2;j>=1 && i<n;j--)
                res[j].push_back(s[i++]);
        }
        string ans="";
        for(auto it:res){
            for(auto it1:it)
                ans+=it1;
        }
        return ans;
    }
};