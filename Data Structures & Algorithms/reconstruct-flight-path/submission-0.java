class Solution {

    Map<String, PriorityQueue<String>> adj = new HashMap<>();
    LinkedList<String> ans = new LinkedList<>();

    private void dfs(String src){

        PriorityQueue<String> pq = adj.get(src);

        while(pq != null && !pq.isEmpty()){
            String nei = pq.poll();
            dfs(nei);
        }

        ans.addFirst(src);
    }

    public List<String> findItinerary(List<List<String>> tickets) {

        for(List<String> t : tickets){
            String u = t.get(0);
            String v = t.get(1);

            adj.putIfAbsent(u, new PriorityQueue<>());
            adj.get(u).offer(v);
        }

        dfs("JFK");

        return ans;
    }
}