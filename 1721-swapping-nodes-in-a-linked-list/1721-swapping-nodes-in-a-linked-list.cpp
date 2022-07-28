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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>vec;
        ListNode *temp = head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *root = NULL;
        ListNode *t = NULL;
        swap(vec[k-1],vec[vec.size()-k]);
        for(int i=0;i<vec.size();i++){
            if(root==NULL){
                root = t = new ListNode(vec[i]);
            }
            else{
                ListNode *newnode = new ListNode(vec[i]);
                t->next=newnode;
                t=t->next;
            }
        }
        return root;
    }
};