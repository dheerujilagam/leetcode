//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        int n = s.size();
        vector<Node*> ans;
        vector<int> f1(26, 0), f2(26, 0);
        for(char it : s) f1[it - 'a']++;
        Node* st = head, *end = head;
        int count = 0;
        while(end) {
            f2[end -> data - 'a']++;
            count++;
            if(f1 == f2) {
                Node* c1 = NULL, *c2 = NULL;
                while(st != end -> next){
                    if(c1 == NULL) c1 = c2 = new Node(st -> data);
                    else {
                        c2 -> next = new Node(st -> data);
                        c2 = c2 -> next;
                    }
                    st = st -> next;
                }
                ans.push_back(c1);
                st = end -> next;
                end = st;
                for(int i = 0; i < 26; i++) f2[i] = 0;
                count = 0;
            }
            else {
                end = end -> next;
                if(count >= n) {
                    f2[st -> data - 'a']--;
                    st = st -> next;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends