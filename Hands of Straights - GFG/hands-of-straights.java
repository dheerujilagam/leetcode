//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            boolean ans = obj.isStraightHand(n, k, a);
            System.out.println(ans ? "True" : "False");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static boolean isStraightHand(int n, int gs, int arr[]) {
        // code here
        if (n % gs != 0) return false;
        Arrays.sort(arr);
        Map<Integer, Integer> mp = new HashMap<>();
        for (int it : arr) mp.put(it, mp.getOrDefault(it, 0) + 1);
        for (int it : arr) {
            int cnt = gs;
            int val = it;
            while (mp.containsKey(val) && cnt > 0) {
                mp.put(val, mp.get(val) - 1);
                cnt--;
                if (mp.get(val) == 0) mp.remove(val);
                val++;
            }
            if (cnt != 0 && cnt != gs) return false;
        }
        return true;
    }
}
