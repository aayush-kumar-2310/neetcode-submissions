class Solution {
   public:
    bool canFinish(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& currVis) {
        if (currVis[node]) return false;
        if (vis[node]) return true;

        currVis[node] = true;
        vis[node] = true;

        for (auto course : adj[node]) {
            if (!canFinish(course, adj, vis, currVis)) return false;
        }

        currVis[node] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses), currVis(numCourses);

        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!canFinish(i, adj, vis, currVis)) return false;
            }
        }

        return true;
    }
};