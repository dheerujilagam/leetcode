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
        ListNode* slow = head;
        vector<int>res;
        while(slow){
            res.push_back(slow->val);
            slow=slow->next;
        }
        ListNode *root=NULL;
        ListNode *temp=NULL;
        for(int i=0;i<res.size();i++){
            if(i==res.size()/2)
                continue;
            else{
                if(root==NULL)
                    root=temp=new ListNode(res[i]);
                else{
                    ListNode *newnode = new ListNode(res[i]);
                    temp->next=newnode;
                    temp=temp->next;
                }
            }
        }
        return root;
    }
};