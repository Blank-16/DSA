class Solution {
    public int firstUniqChar(String s) {
        var freq = new HashMap<Character, Integer> ();
        for(int i = 0; i < s.length(); i++) {
            freq.merge(s.charAt(i), 1, Integer::sum);
        }

        for(int i = 0; i < s.length(); i++) {
            if(freq.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        return -1; 
    }
}