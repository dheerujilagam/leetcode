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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){return head;}
        ListNode* l = head;
        int len = 1;
        while(l->next && ++len)
            l = l->next;          
        k = k % len;
        k = len - k;
        l->next=head;
        while(k--)
            l = l->next;
        head = l->next;
        l->next = NULL;
        return head;
    }
};