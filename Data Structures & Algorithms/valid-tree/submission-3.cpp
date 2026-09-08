class Solution {
   public:
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& vis) {
        if (vis[node] && node != parent) return false;

        vis[node] = true;

        for (int i : graph[node]) {
            if (i == parent) continue;

            if (vis[i]) return false;

            if (!dfs(i, node, graph, vis)) return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);

        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                if (!dfs(i, -1, graph, vis)) return false;
            }
        }

        return components == 1;
    }
};
