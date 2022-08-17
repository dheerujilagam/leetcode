class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] characters = new String[] {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashSet<String> hash_Set = new HashSet<String>();
        for(String str:words){
            String s="";
            for(int j=0;j<str.length();j++)
                s+=characters[str.charAt(j)-'a'];
            hash_Set.add(s);
        }
        return hash_Set.size();
    }
}