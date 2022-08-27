class Solution {
public:
    int minOperations(int n) {
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i]=(2*i)+1;
        int avg=(accumulate(arr,arr+n,0)/n);
        int ind=n/2;
        if(n%2==0)
            ind--;
        int op=0;
        for(int i=0;i<=ind;i++)
            op+=(avg-arr[i]);
        return op;
    }
};