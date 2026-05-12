class Solution {

    private boolean traverse(int node, boolean[] vis, boolean[] currVis, List<List<Integer>> adj){
        if(currVis[node])
            return false;

        if(vis[node])
            return true;

        currVis[node] = true;
        vis[node] = true;

        for(Integer nei: adj.get(node)){
            if(!traverse(nei, vis, currVis, adj))
                return false;
        }
        currVis[node] = false;
        return true;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        boolean[] vis = new boolean[numCourses];
        boolean[] currVis = new boolean[numCourses];

        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>());
        }

        for(int[] pre : prerequisites){
            adj.get(pre[0]).add(pre[1]);
        }

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(!traverse(i, vis, currVis, adj))   
                    return false;
            }
        }

        return true;

    }
}
