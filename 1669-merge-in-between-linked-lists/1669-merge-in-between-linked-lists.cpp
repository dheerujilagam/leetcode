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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        ListNode *t1 = l1;
        for(int i=0;i<a-1;i++){
            t1=t1->next;
        }
        ListNode* rem = t1->next;
        //return rem;
        ListNode* t2 = l2;
        t1->next = t2;
        for(int i=0;i<b-a+1;i++){
            rem=rem->next;
        }
        
        //return rem;
        //ListNode* r = rem->next;
       while(t1->next!=NULL){
            t1=t1->next;
        }
        
        t1->next=rem;
        return l1;
    }
};