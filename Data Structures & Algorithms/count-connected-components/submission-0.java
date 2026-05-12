class Solution {

    public void solve(int node, boolean[] vis, List<List<Integer>> adj){
        vis[node] = true;

        for(Integer it: adj.get(node)){
            if(!vis[it])
                solve(it, vis, adj);
        }
        return;
    }

    public int countComponents(int n, int[][] edges) {
        boolean[] vis = new boolean[n];
        List<List<Integer>> adj = new ArrayList<>();
        int ans = 0;
        for(int i=0; i<n; i++)
            adj.add(new ArrayList<>());
        
        for(int[] it: edges){
            int u = it[0];
            int v = it[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                solve(i, vis, adj);
            }
        }

        return ans;
    }
}
