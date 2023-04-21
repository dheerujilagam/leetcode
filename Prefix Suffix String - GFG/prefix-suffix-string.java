//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;

public class code1 
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            String s1[]=in.readLine().trim().split(" ");
            String s2[]=in.readLine().trim().split(" ");

            Solution ob=new Solution();
            int ans=ob.prefixSuffixString(s1,s2);
            out.println(ans);

        }
        out.close();
    }
}
// } Driver Code Ends


class Trie {
    HashMap<Character, Trie> children;
    public Trie() {
        children = new HashMap<Character, Trie>();
    }
}

class Solution {   
    Trie root;
    public Solution() {
        root = new Trie();
    }
    
    public void insert(String word) {
        Trie cur = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if(!cur.children.containsKey(c)) cur.children.put(c, new Trie());
            cur = cur.children.get(c);
        }
    }
    
    public boolean search(String word) {
        Trie cur = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if(!cur.children.containsKey(c)) return false;
            cur = cur.children.get(c);
        }
        return true;
    }
    
    public int prefixSuffixString(String s1[],String s2[]) {
        for(String s : s1) {
            insert(s);
            String t = "";
            for(int i = s.length() - 1; i >= 0; i--) t += s.charAt(i);
            insert(t);
        }
        int ans = 0;
        for(String s : s2) {
            String t = "";
            for(int i = s.length() - 1; i >= 0; i--) t += s.charAt(i);
            if(search(s) || search(t)) ans++;
        }
        return ans;
    }
}
