//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int>> &pre) {
	    // Code here
	    vector<int>adj[n];
	    for(auto it:pre){
	        adj[it.second].push_back(it.first);
	    }
	    vector<int>inDeg(n,0);
	    for(int i=0;i<n;i++){
	        for(auto it:adj[i]){
	            inDeg[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<n;i++){
	        if(inDeg[i]==0)
	            q.push(i);
	    }
	    int c=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ++c;
	        for(int it:adj[node]){
	            if(--inDeg[it]==0)
	                q.push(it);
	        }
	    }
	    return c==n;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends