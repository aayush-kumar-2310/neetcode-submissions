class Solution {

    private boolean solve(int node, int par, boolean[] vis, int[] parent, List<List<Integer>> adj){
        vis[node] = true;
        parent[node] = par;
        for(Integer it: adj.get(node)){
            if(!vis[it]){
                if(!solve(it, node, vis, parent, adj))
                    return false;
            }else if(vis[it] && it != par)
                return false;
        }
        return true;
    }

    public boolean validTree(int n, int[][] edges) {
        boolean[] vis = new boolean[n];
        int[] parent = new int[n];
        parent[0] = -1;
        List<List<Integer>> adj = new ArrayList<>();

        for(int i=0; i<n; i++)
            adj.add(new ArrayList<>());

        for(int[] arr: edges){
            int a = arr[0], b = arr[1];
            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        if(!solve(0, -1, vis, parent, adj))
            return false;
        for(int i=0; i<n; i++)
            if(!vis[i])
                return false;
        return true;
    }
}
