import java.util.*;

class Solution {
    public long[] earliestActivationTimes(int n, int[][] edges, int[] requiredSignals) {
        List<int[]>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        for (int[] e : edges)
            adj[e[0]].add(new int[] { e[1], e[2] });

        long[] ans = new long[n];
        Arrays.fill(ans, -1);

        int[] count = new int[n];

        PriorityQueue<long[]> pq = new PriorityQueue<>(
                (a, b) -> Long.compare(a[0], b[0]));

        ans[0] = 0;

        for (int[] e : adj[0])
            pq.offer(new long[] { e[1], e[0] });

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();

            long time = curr[0];
            int v = (int) curr[1];

            if (ans[v] != -1)
                continue;

            if (++count[v] == requiredSignals[v]) {
                ans[v] = time;

                for (int[] e : adj[v])
                    pq.offer(new long[] { time + e[1], e[0] });
            }
        }

        return ans;
    }
}