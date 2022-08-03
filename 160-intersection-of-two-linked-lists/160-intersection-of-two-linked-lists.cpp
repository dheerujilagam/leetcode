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
    int count(ListNode* root){
        int ct=0;
        while(root!=NULL){
            ct++;
            root=root->next;
        }
        return ct;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=count(headA);
        int c2=count(headB);
        ListNode *l1 = headA;
        ListNode *l2 = headB;
        if(c1>c2){
            for(int i=0;i<c1-c2;i++){
                l1=l1->next;
            }
        }
        if(c2>c1){
            for(int i=0;i<c2-c1;i++){
                l2=l2->next;
            }
        }
        ListNode *res=NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1==l2){
                res=l1;
                break;
            }
            l1=l1->next;
            l2=l2->next;
        }
        return res;
    }
};