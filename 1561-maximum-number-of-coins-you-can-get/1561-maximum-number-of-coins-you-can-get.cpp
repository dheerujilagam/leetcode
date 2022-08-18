class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        deque<int>dq(piles.begin(),piles.end());
        int tot=0;
        while(!dq.empty()){
            dq.pop_back();
            tot+=dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        return tot;
    }
};