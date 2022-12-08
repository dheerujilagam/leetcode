//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int sieve(long long n){
        n=sqrt(n);
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i) prime[j]=false;
            }
        }
        int c=0;
        for(int i=2;i<=n;i++){
            if(prime[i]) c++;
        }
        return c;
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int>res;
        for(auto it:query){
            int val=sieve(it);
            res.push_back(val);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends