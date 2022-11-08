//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int index(int val){
        int ind=0;
        while(val){
            if(val&1)
                return ind;
            val=val>>1;
            ind++;
        }
        return ind;
    }
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        int x=Arr[0];
        for(long long int i=1;i<N;i++){
            x^=Arr[i];
        }
        int pos=index(x);
        int t=x;
        for(long long int i=0;i<N;i++){
            int temp=1<<pos;
            if(Arr[i]&temp)
                t^=Arr[i];
        }
        int a=t^x,b=t;
        if(a>b)
            return {a,b};
        return {b,a};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends