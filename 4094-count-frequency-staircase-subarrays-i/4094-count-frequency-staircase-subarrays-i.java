class Solution {
    public int countStaircase(int[] nums) {
        int n = nums.length, ans = 0;

        for (int i = 0; i < n; i++) {
            int[] freq = new int[100001];
            int[] first = new int[n];
            int distinct = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (freq[x] == 0)
                    first[distinct++] = x;

                freq[x]++;

                if (freq[x] > distinct) break;

                boolean ok = true;
                for (int t = 0; t < distinct; t++) {
                    if (freq[first[t]] != t + 1) {
                        ok = false;
                        break;
                    }
                }

                if (ok) ans++;
            }
        }

        return ans;
    }
}