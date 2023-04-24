//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG{
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- > 0) {
			int n = Integer.parseInt(br.readLine());
			int [] arr = new int[n];
			String [] str = br.readLine().trim().split(" ");
			for(int i = 0; i < n; i++)
				arr[i] = Integer.parseInt(str[i]);
			Solution ob = new Solution();
			int [] ans = ob.nearestSmallestTower(arr);
			for(int i = 0; i < n; i++)
				System.out.print(ans[i]+" ");
			System.out.println();
		}
		
	}
}
// } Driver Code Ends


//User function Template for Java


class Solution{
	int [] nearestSmallestTower(int [] arr){
		//Write your code here
		int n = arr.length;
		Stack<Integer> st = new Stack<>();
		int [] ans = new int[n];
		for(int i = 0; i < n; i++) {
		    while(!st.empty() && arr[i] <= arr[st.peek()]) {
		        st.pop();
		    }
		    if(!st.empty()) ans[i] = st.peek();
		    else ans[i] = -1;
		    st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i = n - 1; i >= 0; i--) {
		    while(!st.empty() && arr[i] <= arr[st.peek()]) {
		        st.pop();
		    }
		    if(!st.empty()) {
		        if(ans[i] == -1) ans[i] = st.peek();
		        else if(Math.abs(i - ans[i]) > Math.abs(i - st.peek())) ans[i] = st.peek();
		        else if(Math.abs(i - ans[i]) == Math.abs(i - st.peek())) if(arr[ans[i]] > arr[st.peek()]) ans[i] = st.peek();
		    }
		    st.push(i);
		}
		return ans;
	}
}