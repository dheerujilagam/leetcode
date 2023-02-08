//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<vector<int>>moves{{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int n)
	{
	    int stx=kp[0]-1,sty=kp[1]-1;
	    int endx=tp[0]-1,endy=tp[1]-1;
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	    pq.push({0,{stx,sty}});
	    vis[stx][sty]=1;
	    while(!pq.empty()){
	        auto p=pq.top();
	        pq.pop();
	        int count=p.first;
	        int i=p.second.first,j=p.second.second;
	        if(i==endx && j==endy)
	            return count;
	        for(int k=0;k<8;k++){
	            int x=i+moves[k][0],y=j+moves[k][1];
	            if(x<0 || y<0 || x>=n || y>=n || vis[x][y])
	                continue;
	            vis[x][y]=1;
	            pq.push({count+1,{x,y}});
	        }
	    }
	    return -1;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends