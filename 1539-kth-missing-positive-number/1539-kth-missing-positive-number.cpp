class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j=0,val=k;
        for(int i=1;i<=1000;i++){
            if(j<arr.size() and arr[j]==i)
                j++;
            else
                k--;
            if(k==0)
                return i;
        }
        return 1000+k;
    }
};