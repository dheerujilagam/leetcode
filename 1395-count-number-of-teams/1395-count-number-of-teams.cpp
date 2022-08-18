class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            int c11 = 0, c12 = 0;
            int c21 = 0, c22 = 0;
            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) c11++;
                if(rating[j] > rating[i]) c12++;
            }
            for(int j = i+1; j < n; j++) {
                if(rating[j] > rating[i]) c21++;
                if(rating[j] < rating[i]) c22++;
            }
            cnt += c11*c21 + c12*c22;
        }
        return cnt;
    }
};