class Solution {
public:
    int digSum(int n){
        int sum=0;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int countBalls(int l, int h) {
        map<int,int>mp;
        for(int i=l;i<=h;i++)
            mp[digSum(i)]++;
        int max_cnt=0;
        for(auto it:mp){
            if(it.second>max_cnt)
                max_cnt=it.second;
        }
        return max_cnt;
    }
};