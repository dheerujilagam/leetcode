//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG{
	public static void main(String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- > 0) {
			String [] str = br.readLine().trim().split(" ");
			int n = Integer.parseInt(str[0]);
			int k = Integer.parseInt(str[1]);
			int [] sweetness = new int[n];
			str = br.readLine().trim().split(" ");
			int i = 0;
			for(String s: str) {
				sweetness[i++] = Integer.parseInt(s);
			}
			Solution obj = new Solution();
			System.out.println(obj.maxSweetness(sweetness, n, k));
		}
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    boolean search(int [] s, int m, int k) {
        int sum = 0;
        for(int it : s) {
            sum += it;
            if(sum >= m) {
                sum = 0;
                k--;
            }
        }
        return k <= -1;
    }
	int maxSweetness(int [] s, int n, int k) {
	    int l = Integer.MAX_VALUE, h = 0;
	    for(int it : s) {
	        l = Math.min(it, l);
	        h += it;
	    }
	    int m;
	    while(l <= h) {
	        m = (h + l) / 2;
	        if(search(s, m, k)) l = m + 1;
	        else h = m - 1;
	    }
	    return l - 1;
	}
}