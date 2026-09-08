class Solution {
   public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis) {
        if (vis[node]) return;

        vis[node] = true;

        for (int i : graph[node]) dfs(i, graph, vis);

        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n, vector<int>(n));

        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, graph, vis);
            }
        }

        return ans;
    }
};
