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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
            return NULL;
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        ListNode *s=head;
        ListNode *f=head;
        ListNode *r=NULL;
        while(f!=NULL && f->next!=NULL){
            r=s;
            s=s->next;
            f=f->next->next;
        }
        r->next=s->next;
        s->next=NULL;
        return head;
    }
};