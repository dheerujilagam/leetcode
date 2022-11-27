//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    int n=a.size(),m=b.size();
	    if(n>m){
	        int t=n-m;
	        while(t--){
	            b='0'+b;
	        }
	    }
	    if(m>n){
	        int t=m-n;
	        while(t--){
	            a='0'+a;
	        }
	    }
	    int l=max(n,m);
	    char sum[l];
	    char carry='0';
	    for(int i=l-1;i>=0;i--){
	        if(a[i]=='0' && b[i]=='0' && carry=='0'){
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1'){
                sum[i]='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0'){
                sum[i]='1';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1'){
                sum[i]='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0'){
                sum[i]='1';
                carry='0';
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1'){
                sum[i]='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0'){
                sum[i]='0';
                carry='1';
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1'){
                sum[i]='1';
                carry='1';
            }
	    }
	    if(carry=='1'){
	        string res="1";
	        for(int i=0;i<l;i++)
	            res+=sum[i];
	        return res;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends