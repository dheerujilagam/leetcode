class Solution {
    static void reverse(int a[], int n) { 
        int i,k,t; 
        for(i=0;i<n/2;i++) { 
            t=a[i]; 
            a[i]=a[n-i-1]; 
            a[n-i-1]=t; 
        } 
    }
    public boolean isMonotonic(int[] nums) {
        int []t=nums.clone();
        Arrays.sort(t);
        if(Arrays.equals(t,nums))
            return true;
        reverse(nums,nums.length);
        if(Arrays.equals(nums,t))
            return true;
        return false;
    }
}