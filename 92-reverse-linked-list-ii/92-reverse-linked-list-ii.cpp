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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp=head;
        stack<int>st;
        int i=1;
        while(temp!=NULL){
            if(i>=left and i<=right){
                st.push(temp->val);
                temp=temp->next;
            }
            else
                temp=temp->next;
            i++;
        }
        temp=head;
        i=1;
        while(temp!=NULL){
            if(i>=left and i<=right){
                temp->val=st.top();
                st.pop();
                temp=temp->next;
            }
            else
                temp=temp->next;
            i++;
        }
        return head;
    }
};