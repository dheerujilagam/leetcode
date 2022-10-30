//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& sl) {
        //code here
        vector<vector<string>>ans;
        map<string,vector<string>>mp;
        for(auto it:sl){
            string t=it;
            sort(t.begin(),t.end());
            mp[t].push_back(it);
        }
        for(auto i:mp){
            vector<string>temp;
            for(auto j:i.second){
                temp.push_back(j);
            }
            //sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends