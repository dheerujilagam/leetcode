class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>ans;
        int x=1;
        for(int i=2;i<=encoded.size()+1;i++)
            x=x^i;
        for(int i=1;i<encoded.size();i+=2)
            x=x^encoded[i];
        ans.push_back(x);
        for(int i=1;i<encoded.size()+1;i++){
            ans.push_back(ans[i-1]^encoded[i-1]);
        }
        return ans;
    }
};