class Solution {
    private static final int MOD = 1_000_000_007;

    private int digitSumOf(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    public int countArrays(int[] digitSum) {
        // Step 1: group numbers 0..5000 by digit sum
        ArrayList<Integer>[] groups = new ArrayList[51];
        for (int i = 0; i <= 50; i++) {
            groups[i] = new ArrayList<>();
        }
        for (int i = 0; i <= 5000; i++) {
            groups[digitSumOf(i)].add(i);
        }

        // If the first group is empty, no valid array exists
        if (groups[digitSum[0]].isEmpty()) return 0;

        // Step 2: base DP — each number in the first group can stand alone
        long[] dp = new long[groups[digitSum[0]].size()];
        Arrays.fill(dp, 1);

        // Step 3: transitions
        for (int i = 1; i < digitSum.length; i++) {
            ArrayList<Integer> prev = groups[digitSum[i - 1]];
            ArrayList<Integer> curr = groups[digitSum[i]];

            if (curr.isEmpty()) return 0;

            // prefix sums of dp
            long[] prefix = new long[dp.length];
            prefix[0] = dp[0];
            for (int j = 1; j < dp.length; j++) {
                prefix[j] = (prefix[j - 1] + dp[j]) % MOD;
            }

            long[] next = new long[curr.size()];
            int k = 0; // pointer into prev

            for (int j = 0; j < curr.size(); j++) {
                // advance k while prev[k] <= curr[j]
                while (k < prev.size() && prev.get(k) <= curr.get(j)) {
                    k++;
                }
                if (k > 0) {
                    next[j] = prefix[k - 1];
                }
            }

            dp = next;
        }

        // Step 4: sum all ways
        long ans = 0;
        for (long v : dp) {
            ans = (ans + v) % MOD;
        }
        return (int) ans;
    }
}