class Solution {
    public String breakPalindrome(String p) {
        int n=p.length();
        if(n==1)
            return "";
        StringBuilder s = new StringBuilder(p);
        for(int i=0;i<n/2;i++){
            if(s.charAt(i)!='a'){
                s.setCharAt(i,'a');
                return s.toString();
            }
        }
        s.setCharAt(n-1,'b');
        return s.toString();
    }
}