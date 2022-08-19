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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        /*if(head->val != val){
            head->next = removeElements(head->next,val);
            return head;
        }
        else return removeElements(head->next,val);*/
        while(head!=NULL and head->val==val) head = head->next;
        ListNode *cur = head;
        while(cur!=NULL and cur->next!=NULL){
            if(cur->next->val == val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};