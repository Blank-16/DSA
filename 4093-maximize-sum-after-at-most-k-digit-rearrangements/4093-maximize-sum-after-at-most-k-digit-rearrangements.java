class Solution {
    public long maximizeSum(int[] nums, int k) {
        long sum = 0;

        PriorityQueue<Long> pq = new PriorityQueue<>();

        for(int num : nums) {
            sum += num;

            char[] d = String.valueOf(num).toCharArray();
            Arrays.sort(d);

            long max = 0;
            for(int i = d.length - 1; i >= 0; i--) {
                max = max * 10 + d[i] - '0';
            }

            long gain = max - num;
            if (gain > 0) {
                pq.offer(gain);
                if(pq.size() > k) pq.poll();
            }
        }
        while(!pq.isEmpty()) sum += pq.poll();
        return sum;
    }
}