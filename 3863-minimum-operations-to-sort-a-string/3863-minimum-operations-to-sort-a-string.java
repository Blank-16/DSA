class Solution {
    public int minOperations(String s) {
        int n = s.length();
        if (n == 1)
            return 0;
        if (n == 2)
            return s.charAt(0) > s.charAt(1) ? -1 : 0;

        char mn = 'z', mx = 'a';
        char first = s.charAt(0), last = s.charAt(n - 1);
        boolean sorted = true;
        int[] count = new int[26];

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            mn = (char) Math.min(mn, c);
            mx = (char) Math.max(mx, c);
            count[c-'a']++;
            if (i > 0 && s.charAt(i) < s.charAt(i - 1)) {
                sorted = false;
            }
        }

        if (sorted)
            return 0;
        if (first == mn || last == mx)
            return 1;
        if (first != mx || last != mn)
            return 2;

        return (count[mx - 'a'] > 1 || count[mn - 'a'] > 1) ? 2 : 3;
    }
}