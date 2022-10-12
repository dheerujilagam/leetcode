class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1;
        vector<int>ans;
        for(int i=digits.size()-1;i>=0;i--){
            int sum=digits[i]+c;
            ans.push_back(sum%10);
            c=sum/10;
        }
        if(c>0){
            ans.push_back(c);
        }
        int s=0,e=ans.size()-1;
        while(s<e){
            int temp=ans[s];
            ans[s]=ans[e];
            ans[e]=temp;
            s++;
            e--;
        }
        return ans;
    }
};