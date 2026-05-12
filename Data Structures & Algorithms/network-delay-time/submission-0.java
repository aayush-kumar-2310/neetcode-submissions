class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int []>> adj = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[0] - b[0]);
        
        int[] dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[k] = 0;
        pq.offer(new int[]{0, k});

        for(int i=0; i<=n; i++){
            adj.add(new ArrayList<>());
        }

        for(int[] it: times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj.get(u).add(new int[]{v, w});
        }

        while(!pq.isEmpty()){
            int[] top = pq.poll();
            int d1 = top[0];
            int node = top[1];

            for(int[] it: adj.get(node)){
                int nei = it[0];
                int d = it[1];
                if(d1+d < dist[nei]){
                    dist[nei] = d1+d;
                    pq.offer(new int[]{d1+d, nei});
                }
            }
        }

        int ans = Integer.MIN_VALUE;

        for(int i=1; i<=n; i++){
            if(dist[i] == Integer.MAX_VALUE)
                return -1;
            else ans = Math.max(ans, dist[i]);
        }

        return ans;
    }
}
