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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head;
        map<int,int>mp;
        vector<int>vec;
        while(temp!=NULL){
            mp[temp->val]++;
            vec.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *root=NULL;
        ListNode *t=NULL;
        for(int i=0;i<vec.size();i++){
            if(root==NULL){
                if(mp[vec[i]]==1){
                    root=t=new ListNode(vec[i]);
                }
            }
            else{
                if(mp[vec[i]]==1){
                    ListNode *newnode = new ListNode(vec[i]);
                    t->next=newnode;
                    t=t->next;
                }
            }
        }
        return root;
    }
};