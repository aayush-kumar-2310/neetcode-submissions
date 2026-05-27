class Solution {
   public:
    bool traverse(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& currVis,
                  stack<int>& st) {
        if (currVis[node]) return false;
        if (vis[node]) return true;

        currVis[node] = true;
        vis[node] = true;

        for (auto course : adj[node])
            if (!traverse(course, adj, vis, currVis, st)) return false;

        st.push(node);
        currVis[node] = false;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses), currVis(numCourses);
        stack<int> st;

        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!traverse(i, adj, vis, currVis, st)) return {};
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};