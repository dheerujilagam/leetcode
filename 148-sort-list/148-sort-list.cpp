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
    ListNode* sortList(ListNode* head) {
        ListNode *temp = head;
        vector<int>vec;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        sort(vec.begin(),vec.end());
        ListNode *root = NULL;
        ListNode *t = NULL;
        for(int i=0;i<vec.size();i++){
            if(root == NULL)
                root = t = new ListNode(vec[i]);
            else{
                ListNode *newnode = new ListNode(vec[i]);
                t->next=newnode;
                t = t->next;
            }
        }
        return root;
    }
};