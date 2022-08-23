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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:lists){
            ListNode* temp=it;
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* root=NULL;
        ListNode* temp=NULL;
        while(!pq.empty()){
            if(root==NULL){
                root=temp=new ListNode(pq.top());
                pq.pop();
            }
            else{
                ListNode* newnode=new ListNode(pq.top());
                pq.pop();
                temp->next=newnode;
                temp=temp->next;
            }
        }
        return root;
    }
};