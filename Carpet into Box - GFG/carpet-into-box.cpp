//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        priority_queue<int>p1,p2;
        p1.push(a);
        p1.push(b);
        p2.push(c);
        p2.push(d);
        int cnt=0;
        while(!p2.empty()){
            if(p1.top()>p2.top()){
                int val=floor(p1.top()/2);
                p1.pop();
                p1.push(val);
                cnt++;
            }
            else{
                p1.pop();
                p2.pop();
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends