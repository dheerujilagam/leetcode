/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *s = head, *f = head, *cur = head;
        while(f->next!=NULL and f->next->next!=NULL){
            s = s->next;
            f = f->next->next;
            if(s==f){
                while(s!=cur){
                    s = s->next;
                    cur = cur->next;
                }
                return s;
            }
        }
        return NULL;
    }
};