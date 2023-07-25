//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> child;

    TrieNode() {
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root;

    void insert(string& s) {
        TrieNode* cur = root;
        for (char it : s) {
            if (cur->child.find(it) == cur->child.end()) cur->child[it] = new TrieNode();
            cur = cur->child[it];
        }
        cur->isEnd = true;
    }

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    void dfs(int i, int j, vector<vector<char>> &board, TrieNode* node, string &s, vector<string>& res) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#')
            return;

        char ch = board[i][j];
        if (!node->child[ch]) return;
        s.push_back(ch);
        node = node->child[ch];

        if (node->isEnd) {
            res.push_back(s);
            node->isEnd = false;
        }

        board[i][j] = '#';
        for (int k = 0; k < 8; k++) {
            dfs(i + dx[k], j + dy[k], board, node, s, res);
        }
        board[i][j] = ch;
        s.pop_back();
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dict) {
        root = new TrieNode();

        for (string word : dict) insert(word);

        vector<string> res;
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string s;
                dfs(i, j, board, root, s, res);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends