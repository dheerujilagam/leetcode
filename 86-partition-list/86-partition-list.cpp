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
    ListNode* partition(ListNode* head, int x) {
        vector<int>res;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val<x)
                res.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->val>=x)
                res.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *root=NULL;
        temp=NULL;
        for(int i=0;i<res.size();i++){
            if(root==NULL){
                root=temp=new ListNode(res[i]);
            }
            else{
                ListNode *newnode = new ListNode(res[i]);
                temp->next=newnode;
                temp=temp->next;
            }
        }
        return root;
    }
};