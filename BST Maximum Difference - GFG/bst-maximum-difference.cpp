//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int solve(Node* cur) {
        if(cur -> left == NULL && cur -> right == NULL) return cur -> data;
        int l = 0, r = 0;
        if(cur -> left) l += solve(cur -> left);
        if(cur -> right) r += solve(cur -> right);
        if(l == 0) return cur -> data + r;
        if(r == 0) return cur -> data + l;
        return cur -> data + min(l, r);
    }
    int maxDifferenceBST(Node *root, int target){
        Node* cur = root;
        int l = 0;
        while(cur) {
            l += cur -> data;
            if(cur -> data == target) break;
            else if(cur -> data < target) cur = cur -> right;
            else cur = cur -> left;
        }
        if(cur == NULL) return -1;
        return l - solve(cur);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends