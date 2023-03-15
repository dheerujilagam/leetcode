//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    void dfs(Node* root, vector<int> adj[]) {
        if(root != NULL) {
            if(root -> left != NULL) {
                adj[root -> data].push_back(root -> left -> data);
                adj[root -> left -> data].push_back(root -> data);
                dfs(root -> left, adj);
            }
            if(root -> right != NULL) {
                adj[root -> data].push_back(root -> right -> data);
                adj[root -> right -> data].push_back(root -> data);
                dfs(root -> right, adj);
            }
        }
    }
    int findDist(Node* root, int a, int b) {
        vector<int> adj[100001];
        dfs(root, adj);
        vector<bool> vis(100001, false);
        queue<pair<int, int>> q;
        q.push({a, 0});
        vis[a] = true;
        while(!q.empty()) {
            int node = q.front().first;
            int cnt = q.front().second;
            q.pop();
            // cout << cnt << " ";
            if(node == b) return cnt;
            for(int it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = true;
                    q.push({it, cnt + 1});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends