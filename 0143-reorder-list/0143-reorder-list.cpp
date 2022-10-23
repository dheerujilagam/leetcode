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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        vector<int>t;
        while(temp){
            t.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>ans;
        int i=0,j=t.size()-1;
        while(i<j){
            ans.push_back(t[i]);
            ans.push_back(t[j]);
            i++;
            j--;
        }
        if(i==j)
            ans.push_back(t[i]);
        temp=head;
        i=0;
        while(temp){
            temp->val=ans[i];
            temp=temp->next;
            i++;
        }
    }
};