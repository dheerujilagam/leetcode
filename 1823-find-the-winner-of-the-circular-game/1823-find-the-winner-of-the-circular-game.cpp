class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        int j=1;
        while(q.size()!=1){
            if(j!=k){
                int val=q.front();
                q.pop();
                q.push(val);
                j++;
            }
            else{
                q.pop();
                j=1;
            }
        }
        return q.front();
    }
};