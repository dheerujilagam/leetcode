//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        vector<int>dp(n,0);
        vector<char>cap,sml;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                sml.push_back(s[i]);
            }
            else{
                cap.push_back(s[i]);
                dp[i]=1;
            }
        }
        sort(cap.begin(),cap.end());
        sort(sml.begin(),sml.end());
        int i=0,j=0,k=0;
        while(i<n){
            if(dp[i]){
                s[i]=cap[j];
                j++;
            }
            else{
                s[i]=sml[k];
                k++;
            }
            i++;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends