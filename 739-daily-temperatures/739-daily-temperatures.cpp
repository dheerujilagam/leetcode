class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans;
        stack<pair<int,int>>st;
        st.push({temp[n-1],n-1});
        ans.push_back(0);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top().first<=temp[i])
                st.pop();
            if(st.empty())
                ans.push_back(0);
            else
                ans.push_back(st.top().second-i);
            st.push({temp[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};