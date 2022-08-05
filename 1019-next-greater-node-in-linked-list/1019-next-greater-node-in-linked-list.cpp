/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void ngg(vector<int>&ans){
        stack<int>st;
        st.push(0);
        for(int i=ans.size()-1;i>=0;i--){
            int cur=ans[i];
            while(st.size()>1 && st.top()<=cur)
                st.pop();
            ans[i]=st.top();
            st.push(cur);
        }
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        ngg(ans);
        return ans;
    }
};