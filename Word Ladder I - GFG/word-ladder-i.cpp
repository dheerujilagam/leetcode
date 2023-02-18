//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){ 
            string cur=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(cur==endWord)
                return cnt;
            for(int i=0;i<cur.size();i++){
                char ch=cur[i];
                for(char it='a';it<='z';it++){
                    if(ch!=it){
                        cur[i]=it;
                        if(s.count(cur)){
                            q.push({cur,cnt+1});
                            s.erase(s.find(cur));
                        }
                    }
                }
                cur[i]=ch;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends