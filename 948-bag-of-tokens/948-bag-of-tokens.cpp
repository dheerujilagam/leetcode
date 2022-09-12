class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int c=0,mx=0,i=0,j=tokens.size()-1;
        if(tokens.size()>=1 and tokens[0]>power)
            return 0;
        else{
            while(i<=j){
            if(tokens[i]<=power){
                ++c;
                power-=tokens[i];
                ++i;
                if(c>mx)
                    mx=c;
            }
            else{
                --c;
                power+=tokens[j];
                --j;
            }
        }
        return mx;
        }
    }
};