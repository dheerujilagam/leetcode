//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int> prime;
    void precompute() {
        const long long N = 2e6 + 1;
        vector<bool> isprime(N, true);
        for(long long p = 2; p*p <= N; p++) {
            if(isprime[p] == true) {
                for(long long i = p*p; i <= N; i += p){
                    isprime[i] = false;
                }
            }    
        
        }
        for(long long i = 2; i<= N; i++){
            if(isprime[i] == true) {
                prime.push_back(i);
            }
        }
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        if(m == 0) return -1;
        vector<bool> vis(n + 1, false);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i] == false) {
                int count = 0;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    count++;
                    for(int it : g[node]) {
                        if(vis[it] == false) {
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }
                ans = max(ans, count);
            }
        }
        return prime[ans - 1];
    }
    
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends