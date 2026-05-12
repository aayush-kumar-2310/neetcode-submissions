class Solution {

    private boolean solve(int node, boolean[] vis, boolean[] currVis, Stack<Integer> st, List<List<Integer>> adj){

        if(currVis[node])
            return false;
        if(vis[node])
            return true;
        
        vis[node] = true;
        currVis[node] = true;

        for(Integer it: adj.get(node)){
            if (!solve(it, vis, currVis, st, adj))
                return false;
        }
        currVis[node] = false;
        st.push(node);
        return true;
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        int[] ans = new int[numCourses];
        boolean[] vis = new boolean[numCourses];
        boolean[] currVis = new boolean[numCourses];

        for(int i=0; i<numCourses; i++)
            adj.add(new ArrayList<>());

        for(int[] it: prerequisites){
            adj.get(it[1]).add(it[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(!solve(i, vis, currVis, st, adj))
                return new int[]{};
        }
        
        int c=0;
        while(!st.empty()){
            int x = st.pop();
            ans[c] = x;
            c++;
        }

        return ans;
    }
}
